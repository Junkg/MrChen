/******************************************************************************/
/** 模块名称：Modbus通讯                                                     **/
/** 文件名称：mbpdu.c                                                        **/
/** 版    本：V1.0.0                                                         **/
/** 简    介：用于实现modbus总线协议栈PDU部分封装                            **/
/**--------------------------------------------------------------------------**/
/* 一个典型的Modbus数据帧有如下部分组成：                                     */
/* <------------------- MODBUS串行链路应用数据单元（ADU） ----------------->  */
/*              <------ MODBUS简单协议数据单元（PDU） ------->                */
/*  +-----------+---------------+----------------------------+-------------+  */
/*  |  地址域   |    功能码     | 数据域                     | CRC/LRC     |  */
/*  +-----------+---------------+----------------------------+-------------+  */
/*                                                                            */
/* 一个TCP/IP Modbus数据帧由如下部分组成：                                    */
/* <------------------- MODBUS TCP/IP应用数据单元（ADU） ------------------>  */
/*                       <-------- MODBUS简单协议数据单元（PDU） ---------->  */
/*  +--------------------+---------------+---------------------------------+  */
/*  |  MBAP头部          |    功能码     | 数据域                          |  */
/*  +--------------------+---------------+---------------------------------+  */
/**--------------------------------------------------------------------------**/
/** 修改记录：                                                               **/
/**     版本      日期              作者              说明                   **/
/**     V1.0.0  2015-06-17          尹家军            创建文件               **/
/**                                                                          **/
/******************************************************************************/ 
#include "stdafx.h"
#include "mbpdu.h"
#include "windows.h"
/*将布尔量（线圈和输入状态）数组转化为MB字节数组,返回最终数组的长度*/
static /*uint16_t*/UINT16 ConvertBoolArrayToMBByteArray(bool *sData,/*uint16_t*/UINT16 length,/*uint8_t*/UINT * oData);
/*将寄存器（输入寄存器和保持寄存器）数组转化为MB字节数组,返回最终数组的长度*/
static /*uint16_t*/UINT16 ConvertRegisterArrayToMBByteArray(/*uint16_t*/UINT16 *sData,/*uint16_t*/UINT16 length,/*uint8_t*/UINT * oData);
/*将接收到的写Coil字节数组转化为布尔数组*/
static void ConvertMBByteArrayTotBoolArray(/*uint8_t*/UINT * sData,bool *oData);
/*将接收到的写保持寄存器的字节数组专为寄存器数组*/
static void ConvertMBByteArrayToRegisterArray(/*uint8_t*/UINT * sData,/*uint16_t*/UINT16 *oData);

/*作为RTU主站（TCP客户端）时，生成读写RTU从站（TCP服务器）对象的命令*/
/*uint16_t*/UINT16 GenerateReadWriteCommand(ObjAccessInfo objInfo,bool *statusList,/*uint16_t*/UINT16 *registerList,/*uint8_t*/UINT *commandBytes)
{
  /*uint16_t*/UINT16 index=0;
  commandBytes[index++]=objInfo.unitID;                 //从站地址
  commandBytes[index++]=objInfo.functionCode;           //功能码
  commandBytes[index++]=objInfo.startingAddress>>8;     //起始地址高字节
  commandBytes[index++]=objInfo.startingAddress;        //起始地址低字节
  
  /*读从站对象*/
  if((objInfo.functionCode>=ReadCoilStatus)&&(objInfo.functionCode <= ReadInputStatus))
  {
    commandBytes[index++]=objInfo.quantity>>8;
    commandBytes[index++]=objInfo.quantity;
  }
  
  /*写单个线圈数据对象*/
  if((WriteSingleCoil==objInfo.functionCode)&&(statusList!=NULL))
  {
    commandBytes[index++]=(*statusList)?0xFF:0x00;
    commandBytes[index++]=0x00;
  }
  
  /*写单个寄存器数据对象*/
  if((objInfo.functionCode==WriteSingleRegister)&&(registerList!=NULL))
  {
    commandBytes[index++]=(*registerList)>>8;
    commandBytes[index++]=(*registerList);
  }
  
  /*写多个线圈*/
  if((objInfo.functionCode==WriteMultipleCoil)&&(statusList!=NULL))
  {
    commandBytes[index++]=objInfo.quantity>>8;
    commandBytes[index++]=objInfo.quantity;
    /*uint8_t*/UINT byteArray[250];
    /*uint16_t*/UINT16 bytesCount=ConvertBoolArrayToMBByteArray(statusList,objInfo.quantity,byteArray);
    commandBytes[index++]=bytesCount;
    for(int i=0;i<bytesCount;i++)
    {
      commandBytes[index++]=byteArray[i];
    }
  }
  
  /*写多个寄存器*/
  if((objInfo.functionCode==WriteMultipleRegister)&&(registerList!=NULL))
  {
    commandBytes[index++]=objInfo.quantity>>8;		//数量高字节
    commandBytes[index++]=objInfo.quantity;             //数量低字节
    /*uint8_t*/UINT byteArray[250];
    /*uint16_t*/UINT16 bytesCount=ConvertRegisterArrayToMBByteArray(registerList,objInfo.quantity,byteArray);
    commandBytes[index++]=bytesCount;		//字节数量
    for(int i=0;i<bytesCount;i++)
    {
      commandBytes[index++]=byteArray[i];
    }
  }
  return index;
}

/*解析主站（客户端）从服务器读取的数据*/
void TransformClientReceivedData(/*uint8_t*/UINT * receivedMessage,/*uint16_t*/UINT16 quantity,bool *statusList,/*uint16_t*/UINT16 *registerLister)
{
  FunctionCode fc=(FunctionCode)receivedMessage[1];
  /*uint16_t*/UINT16 bytesCount=(/*uint16_t*/UINT16)receivedMessage[2];

  /*转化线圈状态和输入状态数据*/
  if(((fc==ReadInputStatus)||(fc==ReadCoilStatus))&&(statusList!=NULL))
  {
    for(int i=0;i<bytesCount;i++)
    {
      for(int j=0;j<8;j++)
      {
        if((i*8+j)<quantity)
        {
          statusList[i*8+j]=((receivedMessage[i+3]>>j)&0x01)?true:false;
        }
      }
    }
  }
  
  /*转化保持寄存器和输入寄存器数据*/
  if(((fc==ReadHoldingRegister)||(fc==ReadInputRegister))&&(registerLister!=NULL))
  {
    if(bytesCount==quantity*2)
    {
      for(int i=0;i<quantity;i++)
      {
        registerLister[i]=(/*uint16_t*/UINT16)(receivedMessage[i*2+3]);
        registerLister[i]=(registerLister[i]<<8)+(/*uint16_t*/UINT16)(receivedMessage[i*2+4]);
      }
    }
  }
}

/*生成主站读访问的响应，包括0x01、0x02、0x03、0x04功能码,返回相应信息的长度*/
/*uint16_t*/UINT16 GenerateMasterAccessRespond(/*uint8_t*/UINT *receivedMessage,bool *statusList,/*uint16_t*/UINT16 *registerList,/*uint8_t*/UINT *respondBytes)
{
  /*uint16_t*/UINT16 index=0;
  FunctionCode functionCode=(FunctionCode)(*(receivedMessage+1));
  if(CheckFunctionCode(functionCode)!=eMB_OK)
  {
    return 0;
  }
  
  respondBytes[index++]=*receivedMessage;			//从站地址
  respondBytes[index++]=*(receivedMessage+1);			//功能码
  
  /*读线圈或状态量*/
  if(((functionCode==ReadCoilStatus)||(functionCode==ReadInputStatus))&&(statusList!=NULL))
  {
    /*uint16_t*/UINT16 bitsQuantity=*(receivedMessage+4);
    bitsQuantity=(bitsQuantity<<8)+*(receivedMessage+5);
   /* uint8_t*/ UINT byteArray[250];
    memset(byteArray,0,sizeof(byteArray));
    /*uint16_t*/UINT16 bytesCount=ConvertBoolArrayToMBByteArray(statusList,bitsQuantity,byteArray);
    respondBytes[index++]=bytesCount;//字节数
    for(int i=0;i<bytesCount;i++)
    {
      respondBytes[index++]=byteArray[i];	//所写的位的字节
    }
  }

  /*读寄存器数据*/
  if(((functionCode==ReadHoldingRegister)||(functionCode==ReadInputRegister))&&(registerList!=NULL))
  {
    /*uint16_t*/UINT16 registerCount=*(receivedMessage+4);
    registerCount=(registerCount<<8)+*(receivedMessage+5);
   /* uint8_t*/UINT byteArray[250];
    /*uint16_t*/UINT16 bytesCount=ConvertRegisterArrayToMBByteArray(registerList,registerCount,byteArray);
    respondBytes[index++]=bytesCount;		//字节数量
    for(int i=0;i<bytesCount;i++)
    {
      respondBytes[index++]=byteArray[i];	//所写数据
    }
  }
  
  /*写对象操作*/
  if(functionCode>ReadInputRegister)
  {
    respondBytes[index++]=*(receivedMessage+2);
    respondBytes[index++]=*(receivedMessage+3);
    respondBytes[index++]=*(receivedMessage+4);
    respondBytes[index++]=*(receivedMessage+5);
    
    /*写多个线圈操作*/
    if((functionCode==WriteMultipleCoil)&&(statusList!=NULL))
    {
      ConvertMBByteArrayTotBoolArray(receivedMessage,statusList);
    }
    
    /*写多个寄存器*/
    if((functionCode==WriteMultipleRegister)&&(registerList!=NULL))
    {
      ConvertMBByteArrayToRegisterArray(receivedMessage,registerList);
    }
  }

  return index;
}

/*将布尔量（线圈和输入状态）数组转化为MB字节数组,返回最终数组的长度*/
static /*uint16_t*/UINT16 ConvertBoolArrayToMBByteArray(bool *sData,/*uint16_t*/UINT16 length,/*uint8_t*/UINT * oData)
{
  /*uint16_t*/UINT16 returnLength=0;
  if(length>0)
  {
    returnLength=(length-1)/8+1;

    for(int i=0;i<returnLength;i++)
    {
      for(int j=0;j<8;j++)
      {
        if((i*8+j)<length)
        {
          oData[i]=oData[i]+((/*uint8_t*/UINT)sData[i*8+j]<<j);
        }
      }
    }
  }
  
  return returnLength;
}

/*将寄存器（输入寄存器和保持寄存器）数组转化为MB字节数组,返回最终数组的长度*/
static /*uint16_t*/UINT16 ConvertRegisterArrayToMBByteArray(/*uint16_t*/UINT16 *sData,/*uint16_t*/UINT16 length,/*uint8_t*/UINT * oData)
{
  /*uint16_t*/UINT16 returnLength=0;
  if(length>0)
  {
    for(int i=0;i<length;i++)
    {
      oData[returnLength++]=(sData[i]>>8);
      oData[returnLength++]=sData[i];
    }
  }
  return returnLength;
}

/*检查功能码是否正确*/
ModbusStatus CheckFunctionCode(FunctionCode fc)
{
  ModbusStatus status=eMB_OK;
  if((fc<ReadCoilStatus)||((fc>WriteSingleRegister)&&(fc<WriteMultipleCoil))||(fc>WriteMultipleRegister))
  {
    status=InvalidFunctionCode;
  }
  return status;
}

/*将接收到的写Coil字节数组转化为布尔数组*/
static void ConvertMBByteArrayTotBoolArray(/*uint8_t*/UINT * sData,bool *oData)
{
  /*uint16_t*/UINT16 Count=(/*uint16_t*/UINT16)(*(sData+4));
  Count=(Count<<8)+(/*uint16_t*/UINT16)(*(sData+5));
  /*uint16_t*/UINT16 byteCount=(/*uint16_t*/UINT16)(*(sData+6));
  
  for(int i=0;i<byteCount;i++)
  {
    for(int j=0;j<8;j++)
    {
      if((i*8+j)<Count)
      {
        oData[i*8+j]=((sData[i+7]>>j)&0x01)?true:false;
      }
    }
  }
}

/*将接收到的写保持寄存器的字节数组专为寄存器数组*/
static void ConvertMBByteArrayToRegisterArray(/*uint8_t*/UINT * sData,/*uint16_t*/UINT16 *oData)
{
  /*uint16_t*/UINT16 Count=(/*uint16_t*/UINT16)(*(sData+4));
  Count=(Count<<8)+(/*uint16_t*/UINT16)(*(sData+5));
  
  for(int i=0;i<Count;i++)
  {
    oData[i]=(/*uint16_t*/UINT16)(sData[i*2+7]);
    oData[i]=(oData[i]<<8)+(/*uint16_t*/UINT16)(sData[i*2+8]);
  }
}

/*********** (C) COPYRIGHT 1999-2016 Moonan Technology *********END OF FILE****/

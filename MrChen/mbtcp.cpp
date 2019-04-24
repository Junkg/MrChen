#include "stdafx.h"
/****************************************************************
*	用于实现Modbus TCP总线协议站ADU的封装
*	1、实现作为客户端时访问服务器数据命令的生成
*	2、实现作为服务器端时，对客户端命令的响应信息的生成
****************************************************************/

#include "mbtcp.h"

extern uint16_t transactionIDCounter;

/*生成MBAP报文头*/
static uint16_t CreateMbapHeadPart(uint8_t * mbapHead);

/*生成MBAP头数据,为了方便与RTU相同处理，将单元标识符（远程从站地址）放在生成命令时处理*/
/*此处MBAP头只有7个字节，最后单元标识符为默认值0x01*/
static uint16_t CreateMbapHeadPart(uint8_t * mbapHead)
{
	uint16_t index = 0;
	//产生事务标志
	if (transactionIDCounter == 65535)
	{
		transactionIDCounter = 1;
	}
	else
	{
		transactionIDCounter = transactionIDCounter + 1;
	}
	mbapHead[index++] = transactionIDCounter >> 8;//事务标识符
	mbapHead[index++] = transactionIDCounter;//事务标识符
	mbapHead[index++] = 0x00;//协议标识符，modbus标识符为0
	mbapHead[index++] = 0x00;//协议标识符，modbus标识符为0
	mbapHead[index++] = 0x00;//字节长度，此处尚不能确定，在后续更新
	mbapHead[index++] = 0x01;//字节长度，此处尚不能确定，在后续更新
	mbapHead[index++] = 0x01;//单元标识符默认值
	return index;
}

/*生成读写服务器对象的命令*/
uint16_t SyntheticReadWriteTCPServerCommand(ObjAccessInfo objInfo, bool *statusList, uint16_t *registerList, uint8_t *commandBytes)
{
	uint8_t command[256];
	CreateMbapHeadPart(commandBytes);
	uint16_t index = 4;
	uint16_t bytesCount = GenerateReadWriteCommand(objInfo, statusList, registerList, command);
	commandBytes[index++] = bytesCount >> 8;
	commandBytes[index++] = bytesCount;
	for (int i = 0; i < bytesCount; i++)
	{
		commandBytes[index++] = command[i];
	}
	return index;
}

/*合成对服务器访问的响应,返回值为命令长度*/
uint16_t SyntheticServerAccessRespond(uint8_t *receivedMessage, bool *statusList, uint16_t *registerList, uint8_t *respondBytes)
{
	uint16_t index = 0;
	respondBytes[index++] = *receivedMessage;
	respondBytes[index++] = *(receivedMessage + 1);
	respondBytes[index++] = *(receivedMessage + 2);
	respondBytes[index++] = *(receivedMessage + 3);
	uint8_t respond[260];
	uint16_t bytesCount = GenerateMasterAccessRespond(receivedMessage + 6, statusList, registerList, respondBytes);
	respondBytes[index++] = (bytesCount >> 8);
	respondBytes[index++] = bytesCount;

	for (int i = 0; i < bytesCount; i++)
	{
		respondBytes[index++] = respond[i];
	}
	return index;
}
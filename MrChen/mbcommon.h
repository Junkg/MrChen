/******************************************************************************/
/** ģ�����ƣ�ModbusͨѶ                                                     **/
/** �ļ����ƣ�mbcommon.h                                                     **/
/** ��    ����V1.0.0                                                         **/
/** ��    �飺����ʵ��Modbus��������µĹ��ò���                             **/
/**--------------------------------------------------------------------------**/
/** �޸ļ�¼��                                                               **/
/**     �汾      ����              ����              ˵��                   **/
/**     V1.0.0  2015-07-18          ���Ҿ�            �����ļ�               **/
/**                                                                          **/
/******************************************************************************/ 

#include "stdbool.h"
#include "stdint.h"

/*�����յ���д����Coilֵת��Ϊ����������Ӧ0x05������*/
bool CovertSingleCommandCoilToBoolStatus(uint16_t coilValue,bool value);

/*��ȡ��Ҫ��ȡ��Coil����ֵ*/
void GetCoilStatus(uint16_t startAddress,uint16_t quantity,bool *statusList);

/*��ȡ��Ҫ��ȡ��InputStatus����ֵ*/
void GetInputStatus(uint16_t startAddress,uint16_t quantity,bool *statusValue);

/*��ȡ��Ҫ��ȡ�ı��ּĴ�����ֵ*/
void GetHoldingRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue);

/*��ȡ��Ҫ��ȡ������Ĵ�����ֵ*/
void GetInputRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue);

/*���õ�����Ȧ��ֵ*/
void SetSingleCoil(uint16_t coilAddress,bool coilValue);

/*���õ����Ĵ�����ֵ*/
void SetSingleRegister(uint16_t registerAddress,uint16_t registerValue);

/*���ö����Ȧ��ֵ*/
void SetMultipleCoil(uint16_t startAddress,uint16_t quantity,bool *statusValue);

/*���ö���Ĵ�����ֵ*/
void SetMultipleRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue);

/*���¶���������Ȧ״̬*/
void UpdateCoilStatus(uint16_t startAddress,uint16_t quantity,bool *stateValue);

/*���¶�����������״ֵ̬*/
void UpdateInputStatus(uint16_t startAddress,uint16_t quantity,bool *stateValue);

/*���¶������ı��ּĴ���*/
void UpdateHoldingRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue);

/*���¶�����������Ĵ���*/
void UpdateInputResgister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue);

/*********** (C) COPYRIGHT 1999-2016 Moonan Technology *********END OF FILE****/
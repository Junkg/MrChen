/******************************************************************************/
/** ģ�����ƣ�ModbusͨѶ                                                     **/
/** �ļ����ƣ�mbtcpclient.c                                                  **/
/** ��    ����V1.0.0                                                         **/
/** ��    �飺��������Modbus TCP�ͻ��˵�������Լ�����                       **/
/**           1��Modbus TCP�ͻ����û�Ӧ�õĽӿڲ�                            **/
/**           2��ʵ�ַ�����������������ɲ����䴫��Ӧ�ò�                    **/
/**--------------------------------------------------------------------------**/
#include "stdafx.h"
#include "mbtcpclient.h"

#define StoreCommandNumber 10

uint8_t commandClientList[StoreCommandNumber][12];    /*�����ѷ��͵Ķ������б�*/
uint16_t commandClientIndex = 0;        /*���������б���һ������λ��*/
uint16_t transactionIDCounter = 0;/*�����ʶ��*/

/*������������ѷ��������б����������*/
static void AddCommandBytesToList(uint8_t *commandBytes);
/*���յ�������Ϣ���ж��Ƿ��Ƿ��������б�������ķ�����Ϣ��*/
static int FindCommandForRecievedMessage(uint8_t *recievedMessage);
/*�������վ״̬��������Ϣ������Ȧ״̬λ0x012������*/
static void HandleReadCoilStatusRespond(uint8_t *receivedMesasage, uint16_t startAddress, uint16_t quantity);
/*�������վ״̬��������Ϣ��������״̬λ0x02������*/
static void HandleReadInputStatusRespond(uint8_t *receivedMesasage, uint16_t startAddress, uint16_t quantity);
/*�������վ�Ĵ���ֵ�ķ�����Ϣ�������ּĴ���0x03�����룩*/
static void HandleReadHoldingRegisterRespond(uint8_t *receivedMesasage, uint16_t startAddress, uint16_t quantity);
/*�������վ�Ĵ���ֵ�ķ�����Ϣ��������Ĵ���0x04������*/
static void HandleReadInputRegisterRespond(uint8_t *receivedMesasage, uint16_t startAddress, uint16_t quantity);

void(*HandleServerRespond[])(uint8_t *, uint16_t, uint16_t) = { HandleReadCoilStatusRespond,
HandleReadInputStatusRespond,
HandleReadHoldingRegisterRespond,
HandleReadInputRegisterRespond };

/*���ɷ��ʷ�����������*/
uint16_t CreateAccessServerCommand(ObjAccessInfo objInfo, void *dataList, uint8_t *commandBytes)
{
	uint16_t commandLength = 0;
	/*���ɶ���������������������0x01��0x02��0x03��0x04,�����12���ֽ�*/
	if ((objInfo.functionCode >= ReadCoilStatus) && (objInfo.functionCode <= ReadInputStatus))
	{
		commandLength = SyntheticReadWriteTCPServerCommand(objInfo, NULL, NULL, commandBytes);

		AddCommandBytesToList(commandBytes);        /*��¼���͵Ķ�����*/
	}

	/*����Ԥ�÷�������������������0x05,0x0F,������淢�����ݶ���*/
	if ((objInfo.functionCode == WriteSingleCoil) && (objInfo.functionCode == WriteMultipleCoil))
	{
		bool *statusList = (bool*)dataList;
		commandLength = SyntheticReadWriteTCPServerCommand(objInfo, statusList, NULL, commandBytes);
	}

	/*����Ԥ�÷�������������������0x06,0x10,������淢�����ݶ���*/
	if ((objInfo.functionCode == WriteSingleRegister) && (objInfo.functionCode == WriteMultipleRegister))
	{
		uint16_t *registerList = (uint16_t*)dataList;
		commandLength = SyntheticReadWriteTCPServerCommand(objInfo, NULL, registerList, commandBytes);
	}

	return commandLength;
}

/*�����յ��ķ�������Ӧ��Ϣ*/
void ParsingServerRespondMessage(uint8_t *recievedMessage)
{
	/*�жϽ��յ�����Ϣ�Ƿ�����Ӧ������*/
	int cmdIndex = FindCommandForRecievedMessage(recievedMessage);

	if ((cmdIndex < 0))
	{
		return;
	}

	if (recievedMessage[7] > 0x04)
	{
		return;
	}
	FunctionCode fuctionCode = (FunctionCode)recievedMessage[7];

	if (fuctionCode != commandClientList[cmdIndex][7])
	{
		return;
	}

	uint16_t startAddress = (uint16_t)commandClientList[cmdIndex][8];
	startAddress = (startAddress << 8) + (uint16_t)commandClientList[cmdIndex][9];
	uint16_t quantity = (uint16_t)commandClientList[cmdIndex][10];
	quantity = (quantity << 8) + (uint16_t)commandClientList[cmdIndex][11];

	if ((fuctionCode >= ReadCoilStatus) && (fuctionCode <= ReadInputRegister))
	{
		HandleServerRespond[fuctionCode - 1](recievedMessage, startAddress, quantity);
	}
}

/*������������ѷ��������б����������*/
static void AddCommandBytesToList(uint8_t *commandBytes)
{
	if (commandClientIndex > StoreCommandNumber)
	{
		commandClientIndex = 0;
	}

	for (int i = 0; i < 12; i++)
	{
		commandClientList[commandClientIndex][i] = commandBytes[i];
	}

	commandClientIndex++;
}

/*���յ�������Ϣ���ж��Ƿ��Ƿ��������б�������ķ�����Ϣ��*/
/*��������ѷ��������б���ɾ�������������������������Ϣ*/
static int FindCommandForRecievedMessage(uint8_t *recievedMessage)
{
	int cmdIndex = -1;
	for (int i = 0; i < StoreCommandNumber; i++)
	{
		if ((recievedMessage[0] == commandClientList[i][0]) && (recievedMessage[1] == commandClientList[i][1]))
		{
			cmdIndex = i;
			break;
		}
	}

	return cmdIndex;
}

/*�������վ״̬��������Ϣ������Ȧ״̬λ0x01������*/
static void HandleReadCoilStatusRespond(UINT *receivedMessage, uint16_t startAddress, uint16_t quantity)
{
	bool coilStatus[256];

	TransformClientReceivedData(receivedMessage + 6, quantity, coilStatus, NULL);

	UpdateCoilStatus(startAddress, quantity, coilStatus);
}

/*�������վ״̬��������Ϣ��������״̬λ0x02������*/
static void HandleReadInputStatusRespond(uint8_t *receivedMessage, uint16_t startAddress, uint16_t quantity)
{
	bool inputStatus[256];

	TransformClientReceivedData(receivedMessage + 6, quantity, inputStatus, NULL);

	UpdateInputStatus(startAddress, quantity, inputStatus);
}

/*�������վ�Ĵ���ֵ�ķ�����Ϣ�������ּĴ���0x03�����룩*/
static void HandleReadHoldingRegisterRespond(uint8_t *receivedMessage, uint16_t startAddress, uint16_t quantity)
{
	uint16_t holdingRegister[125];

	TransformClientReceivedData(receivedMessage + 6, quantity, NULL, holdingRegister);

	UpdateHoldingRegister(startAddress, quantity, holdingRegister);
}

/*�������վ�Ĵ���ֵ�ķ�����Ϣ��������Ĵ���0x04������*/
static void HandleReadInputRegisterRespond(uint8_t *receivedMessage, uint16_t startAddress, uint16_t quantity)
{
	uint16_t inputRegister[125];

	TransformClientReceivedData(receivedMessage + 6, quantity, NULL, inputRegister);

	UpdateInputResgister(startAddress, quantity, inputRegister);
}
#include "stdafx.h"
#include "mbcommon.h"

bool CovertSingleCommandCoilToBoolStatus(uint16_t coilValue, bool value)
{
	bool state = value;
	if (coilValue == 0x0000)
	{
		state = false;
	}
	if (coilValue == 0xFF00)
	{
		state = true;
	}
	return state;
}

/*获取想要读取的Coil量的值*/
void GetCoilStatus(uint16_t startAddress, uint16_t quantity, bool *statusList)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*获取想要读取的InputStatus量的值*/
void GetInputStatus(uint16_t startAddress, uint16_t quantity, bool *statusValue)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*获取想要读取的保持寄存器的值*/
void GetHoldingRegister(uint16_t startAddress, uint16_t quantity, uint16_t *registerValue)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*获取想要读取的输入寄存器的值*/
void GetInputRegister(uint16_t startAddress, uint16_t quantity, uint16_t *registerValue)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*设置单个线圈的值*/
void SetSingleCoil(uint16_t coilAddress, bool coilValue)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*设置单个寄存器的值*/
void SetSingleRegister(uint16_t registerAddress, uint16_t registerValue)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*设置多个线圈的值*/
void SetMultipleCoil(uint16_t startAddress, uint16_t quantity, bool *statusValue)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*设置多个寄存器的值*/
void SetMultipleRegister(uint16_t startAddress, uint16_t quantity, uint16_t *registerValue)
{
	//如果需要Modbus TCP Server/RTU Slave应用中实现具体内容
}

/*更新读回来的线圈状态*/
void UpdateCoilStatus(uint16_t startAddress, uint16_t quantity, bool *stateValue)
{
	//在客户端（主站）应用中实现
}

/*更新读回来的输入状态值*/
void UpdateInputStatus(uint16_t startAddress, uint16_t quantity, bool *stateValue)
{
	//在客户端（主站）应用中实现
}

/*更新读回来的保持寄存器*/
void UpdateHoldingRegister(uint16_t startAddress, uint16_t quantity, uint16_t *registerValue)
{
	//在客户端（主站）应用中实现
}

/*更新读回来的输入寄存器*/
void UpdateInputResgister(uint16_t startAddress, uint16_t quantity, uint16_t *registerValue)
{
	//在客户端（主站）应用中实现
}

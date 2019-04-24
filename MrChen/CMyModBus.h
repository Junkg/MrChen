#ifndef CMyModBus_H
#define CMyModBus_H
#pragma once

//¹¦ÄÜÂë
#define READ_SINGLE_COL  0x01
#define READ_INPUT 0x02
#define READ_KEEP_REG 0x03
#define READ_INPUT_REG 0x04

#define WRITE_SINGLE_COL 0x05
#define WRITE_SINGLE_REG 0x06
#define WRITE_MULIT_COL 0x0F
#define WRITE_MULIT_REG 0x10

class CMyModBus
{
public:
	CMyModBus();
	~CMyModBus();

private:

};


#endif
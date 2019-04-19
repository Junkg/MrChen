#pragma once


#include "CMyCompletionPort.h"
class CMyComRTU
{
public:
	CMyComRTU();
	~CMyComRTU();

public:
	BOOL  OpenComm(const char * comname);
	BOOL  CloseComm();
	void  PostSend(char * buf , int len  );
	DWORD dwErr;
private :
	HANDLE m_hd; 
	CMyCompletionPort * m_prot;
};


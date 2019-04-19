#include "stdafx.h"
#include "CMyComRTU.h"


CMyComRTU::CMyComRTU()
{
	m_prot = CMyCompletionPort::GetInstance();
}


CMyComRTU::~CMyComRTU()
{
}

BOOL CMyComRTU::OpenComm(const char * comname)
{
	HANDLE hd = CreateFile(CString(comname), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
	if (INVALID_HANDLE_VALUE == hd)
	{
		dwErr = GetLastError();
		return FALSE;

	}

	return 0;
}

BOOL CMyComRTU::CloseComm()
{
	if (INVALID_HANDLE_VALUE != m_hd)
	{
		CloseHandle(m_hd);
	}
	return 0;
}

void CMyComRTU::PostSend(char * buf, int len)
{
	PER_IO_HANDLE  Oper;
	Oper.type = PER_IO_HANDLE::eCom;
	Oper.handle = m_hd;
	Oper.buf = buf;
	Oper.nlen = len;

	
}


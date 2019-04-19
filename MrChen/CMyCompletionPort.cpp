#include "stdafx.h"
#include "CMyCompletionPort.h"

CRITICAL_SECTION CMyCompletionPort::m_lock;
CMyCompletionPort::CMyCompletionPort(){
	InitializeCriticalSection(&m_lock);
	
}

CMyCompletionPort::CMyCompletionPort(const CMyCompletionPort &){

}

//CMyCompletionPort & CMyCompletionPort::operator=(const CMyCompletionPort & object){
//	return (CMyCompletionPort)object;
//}

//在此初始化 
CMyCompletionPort * CMyCompletionPort::m_instance = new CMyCompletionPort();

CMyCompletionPort * CMyCompletionPort::GetInstance()
{
	if (m_instance == NULL)
	{
		EnterCriticalSection(&m_lock);
		if (m_instance == NULL)
		{
			m_instance = new CMyCompletionPort();
		}
		LeaveCriticalSection(&m_lock);
	}
	return m_instance;
}

BOOL CMyCompletionPort::PushOperate(PER_IO_HANDLE buf)
{
	if (INVALID_HANDLE_VALUE == m_hd)
		return FALSE;

	//投递HANDLE 
	HANDLE hd = CreateIoCompletionPort(buf.handle, m_hd, buf.nKey, 0);
	if (INVALID_HANDLE_VALUE == hd)
		return FALSE;

	//投递操作任务

	//记录操作


	return 0;
}

unsigned CMyCompletionPort::MyResult(void * lParam)
{
	CMyCompletionPort *  ptr = (CMyCompletionPort *)lParam; 
	DWORD  dwBytes;
	ULONG_PTR   ulKeys ;
	LPOVERLAPPED lpov  = NULL ; 

	BOOL  bok = GetQueuedCompletionStatus(ptr->m_hd, &dwBytes ,&ulKeys, &lpov, INFINITE);
	if (!bok)
	{
		if (lpov == NULL) //完成端口结束
		{

		}
		else // 某个I/O 操作失败
		{
			//获取key  

			//设置操作失败


		}
	}
	return 0 ;
}

CMyCompletionPort::~CMyCompletionPort()
{
	DeleteCriticalSection(&m_lock);
}

void CMyCompletionPort::Init()
{

	m_hd = CreateIoCompletionPort(NULL, NULL, 0, 0);
	if (m_hd == INVALID_HANDLE_VALUE)
		return;

	//创建线程
	_beginthreadex(NULL, 0, MyResult, m_instance, 0, NULL);


}


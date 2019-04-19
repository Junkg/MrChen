#pragma once
#ifndef MyCompletionPort_h
#define MyCompletionPort_h
#include <process.h>
/*完成端口*/
/*
  单例模式 
*/

typedef struct _PER_IO_HANDLE {
enum eIOResult{eNone,eOk,eFail}; //操作 结果 
enum eType{ eCom , eSocket}; 
HANDLE  handle;
eType  type;
OVERLAPPED ov;
LONG      nKey;  
eIOResult * m_Res;

char * buf; //投放的数组
int  nlen;  //投放大小
CRITICAL_SECTION  look; //用于保护此结构体
}PER_IO_HANDLE, *PPER_IO_HANDLE;



class CMyCompletionPort
{

public:
	static CMyCompletionPort * GetInstance();
	BOOL PushOperate(PER_IO_HANDLE buf);
	static unsigned   WINAPI  MyResult(void *  lParam);
private:
	CMyCompletionPort();
	~CMyCompletionPort();
	CMyCompletionPort(const CMyCompletionPort &);
	CMyCompletionPort & operator= (const CMyCompletionPort &);

	static CMyCompletionPort * m_instance; 
	void Init();
	HANDLE m_hd;
	static CRITICAL_SECTION m_lock;
	
	
};

#endif // MyCompletionPort_h

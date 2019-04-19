#pragma once
#ifndef MyCompletionPort_h
#define MyCompletionPort_h
#include <process.h>
/*��ɶ˿�*/
/*
  ����ģʽ 
*/

typedef struct _PER_IO_HANDLE {
enum eIOResult{eNone,eOk,eFail}; //���� ��� 
enum eType{ eCom , eSocket}; 
HANDLE  handle;
eType  type;
OVERLAPPED ov;
LONG      nKey;  
eIOResult * m_Res;

char * buf; //Ͷ�ŵ�����
int  nlen;  //Ͷ�Ŵ�С
CRITICAL_SECTION  look; //���ڱ����˽ṹ��
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

#pragma once



#include <WS2tcpip.h>
#include <Winsock2.h>

#pragma comment(lib,"WS2_32.lib")

#define BUFSIZE    512 


//客户端  
class CMySocketClient
{
public:
	CMySocketClient();
	~CMySocketClient();
	BOOL InitSock();
	
	BOOL PostConnect(const char * ipadr, int  nport);
	BOOL PostSendBuf();
private:
	SOCKET m_sock;
	WSABUF m_sendBuf;
	WSABUF m_recvBuf;

	WSAEVENT  m_hEConnect;
	WSAEVENT  m_hESend;
	WSAEVENT  m_hERecv;

};

//客户端组管理
class CMyTCPClient
{
	CMyTCPClient();
	~CMyTCPClient();

	void AddSession(CMySocketClient & client);

private:

};

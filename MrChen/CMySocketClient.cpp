#include "stdafx.h"

#include "CMySocketClient.h"



CMySocketClient::CMySocketClient()
{
}


CMySocketClient::~CMySocketClient()
{
	if (m_sock != INVALID_SOCKET)
	{
		delete[]m_recvBuf.buf;
		delete[]m_sendBuf.buf;
		::closesocket(m_sock);
	}
	WSACleanup();
}

BOOL CMySocketClient::InitSock()
{
	WSAData data;
	int  nRet = WSAStartup(MAKEWORD(2, 2), &data);
	if (nRet != 0 )
	{
		return FALSE;
	}

	m_sock = (AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (m_sock == INVALID_SOCKET)
	{
		return FALSE ;  
	}
	m_sendBuf.len = BUFSIZE;
	m_sendBuf.buf = new char[m_sendBuf.len];

	m_recvBuf.len = BUFSIZE;
	m_recvBuf.buf = new char[m_sendBuf.len];
	return TRUE;

}
 

BOOL CMySocketClient::PostConnect(const char * ipadr, int nport)
{
	SOCKADDR_IN  adr_in;
	adr_in.sin_family = AF_INET;
	adr_in.sin_port = htons(nport);
	//adr_in.sin_addr.S_un.S_addr = inet_addr(ipadr);
	inet_pton(AF_INET, ipadr, (PVOID)&adr_in);

	//FLOWSPEC  sec;
	int nRet = WSAConnect(m_sock, (sockaddr *)&adr_in, sizeof(adr_in), NULL, NULL, NULL, NULL);
	if (nRet == SOCKET_ERROR)
	{
		if (GetLastError() != WSAEWOULDBLOCK)
		{
			return FALSE; 
		}
	}

	return TRUE;
}

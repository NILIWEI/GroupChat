#pragma once
#include<cstdio>
#include<WinSock2.h>
#include"proecss_thread.h"
#pragma comment(lib,"Ws2_32.lib")//调用windows系统自带的库文件


class Server
{
private:
	WSADATA m_wsaData;//winsock库版本信息

	SOCKET m_serverSocket;
	SOCKADDR_IN m_server_addr;

	int isFail = 0;
public:
	Server(WSADATA wsaData, SOCKET serverSocket);
	~Server();

	void RequestProtocol();
	void CreateSocket();
	void CreateSocketAddr();
	void Bind();
	void Listen();
	void ClientLink();
	inline int getClientNum() { return m_count; };
	inline int getIsFail() { return isFail; };
};



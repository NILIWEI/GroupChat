#pragma once
#include<cstdio>
#include<WinSock2.h>
#include"process_thread.h"
#pragma comment(lib,"Ws2_32.lib")//调用windows系统自带的库文件


class Client
{
private:
	WSADATA m_wsaData;//winsock库版本信息


	SOCKADDR_IN m_server_addr;
	int isFail = 0;
public:
	Client(WSADATA wsaData, SOCKET serverSocket);
	~Client();

	void RequestProtocol();
	void CreateSocket();
	void CreateSocketAddr();


	void LinkServer();
	inline int getIsFail() { return isFail; };
};

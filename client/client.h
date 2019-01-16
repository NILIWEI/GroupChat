#pragma once
#include<cstdio>
#include<WinSock2.h>
#include"process_thread.h"
#pragma comment(lib,"Ws2_32.lib")//����windowsϵͳ�Դ��Ŀ��ļ�


class Client
{
private:
	WSADATA m_wsaData;//winsock��汾��Ϣ


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

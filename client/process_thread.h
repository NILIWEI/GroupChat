#pragma once
#include<cstdio>
#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")//����windowsϵͳ�Դ��Ŀ��ļ�
#include<graphics.h>

static SOCKET m_serverSocket;
static void Recv_Show() {
	int i = 0;
	char buffer[256];
	int r;
	while (1)
	{
		memset(buffer, 0, 256);
		r = recv(m_serverSocket, buffer, sizeof(buffer) - 1, NULL);
		if (r > 0) {
			outtextxy(0, i * 20, buffer);
			i++;
		}

	}

}

#pragma once
#include<cstdio>
#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")//����windowsϵͳ�Դ��Ŀ��ļ�

static SOCKET clientSocket[1024] = { 0 };
static int m_count;//�ͻ�������
static LPTHREAD_START_ROUTINE commuciation(LPVOID n)
{
	char buffer[1024];
	int r;
	int i = (int)n;
	printf("%d�����ˣ�\n", i);
	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		r = recv(clientSocket[i - 1], buffer, sizeof(buffer) - 1, NULL);
		if (r > 0)
		{
			printf("%d:%s \n", i, buffer);
			for (int j = 0; j < m_count; j++)
				send(clientSocket[j], buffer, sizeof(buffer), NULL);
		}
	}
}

#include"client.h"
#pragma warning(disable:4996)

Client::Client(WSADATA wsaData, SOCKET serverSocket) :
	m_wsaData(wsaData)
{
	m_serverSocket = serverSocket;
}
Client::~Client()
{
	closesocket(m_serverSocket);//关闭服务器
	WSACleanup();//清理服务中间信息
}
void Client::RequestProtocol()
{

	if (LOBYTE(m_wsaData.wVersion) != 2 || HIBYTE(m_wsaData.wVersion) != 2)
	{
		printf("请求版本失败！\n");
		isFail = -1;
	}
}


void Client::CreateSocket()
{

	if (m_serverSocket == -1)
	{
		printf("创建Socket失败！\n");
		isFail = -1;
	}
}
void Client::CreateSocketAddr()
{
	m_server_addr = { 0 };
	m_server_addr.sin_family = AF_INET;
	m_server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	m_server_addr.sin_port = htons(9999);

}
void Client::LinkServer()
{
	int r = connect(m_serverSocket, (sockaddr*)&m_server_addr, sizeof(m_server_addr));
	if (r == -1)
	{
		printf("连接服务器失败！\n");
		isFail = -1;
	}

	//循环通信

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Recv_Show, NULL, NULL, NULL);

	char buffer[256];

	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		printf("请输入信息：");
		scanf("%s", buffer);
		r = send(m_serverSocket, buffer, strlen(buffer), NULL);//发送数据
		if (r > 0)
		{
			printf("\n发送%d字节到服务器成功！\n", r);
		}
	}

}

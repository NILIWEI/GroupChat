#include"server.h"
#pragma warning(disable:4996)
Server::Server(WSADATA wsaData, SOCKET serverSocket) :
	m_wsaData(wsaData), m_serverSocket(serverSocket)
{

}
Server::~Server()
{
	closesocket(m_serverSocket);//关闭服务器
	WSACleanup();//清理服务中间信息
}
void Server::RequestProtocol()
{
	
	if (LOBYTE(m_wsaData.wVersion) != 2 || HIBYTE(m_wsaData.wVersion) != 2)
	{
		printf("请求版本失败！\n");
		isFail = -1;
	}
	printf("请求版本成功！\n");
}

void Server::CreateSocket()
{
	
	if (m_serverSocket == -1)
	{
		printf("创建Socket失败！\n");
		isFail = -1;
	}
	printf("创建Socket成功！\n");
}
void Server::CreateSocketAddr()
{
	m_server_addr = { 0 };
	m_server_addr.sin_family = AF_INET;
	m_server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	m_server_addr.sin_port = htons(9999);

}
void Server::Bind()
{
	int r = bind(m_serverSocket, (sockaddr*)&m_server_addr, sizeof(m_server_addr));
	if (r == -1)
	{
		printf("bind失败！\n");
		isFail = -1;
	}
	printf("bind成功! \n");
}
void Server::Listen()
{
	int num_listen = listen(m_serverSocket, 10);//设置最大监听数目
	if (num_listen == -1)
	{
		printf("listen失败! \n");
		isFail = -1;
	}
	printf("listen成功！\n");
}


void Server::ClientLink()
{
	SOCKADDR_IN m_client_addr = { 0 };
	int len = sizeof(m_client_addr);
	int i = 0;
	while (i < 1024)
	{
		clientSocket[i++] = accept(m_serverSocket, (sockaddr*)&m_client_addr, &len);
		m_count++;
		if (clientSocket[i - 1] == SOCKET_ERROR)
		{
			printf("客户端请求失败！\n");
			Server::~Server();
		}
		printf("新客户加入：%s\n", inet_ntoa(m_client_addr.sin_addr));
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)commuciation, (LPVOID)i, NULL, NULL);
	}

}










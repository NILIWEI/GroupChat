#include"server.h"
#pragma warning(disable:4996)
Server::Server(WSADATA wsaData, SOCKET serverSocket) :
	m_wsaData(wsaData), m_serverSocket(serverSocket)
{

}
Server::~Server()
{
	closesocket(m_serverSocket);//�رշ�����
	WSACleanup();//��������м���Ϣ
}
void Server::RequestProtocol()
{
	
	if (LOBYTE(m_wsaData.wVersion) != 2 || HIBYTE(m_wsaData.wVersion) != 2)
	{
		printf("����汾ʧ�ܣ�\n");
		isFail = -1;
	}
	printf("����汾�ɹ���\n");
}

void Server::CreateSocket()
{
	
	if (m_serverSocket == -1)
	{
		printf("����Socketʧ�ܣ�\n");
		isFail = -1;
	}
	printf("����Socket�ɹ���\n");
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
		printf("bindʧ�ܣ�\n");
		isFail = -1;
	}
	printf("bind�ɹ�! \n");
}
void Server::Listen()
{
	int num_listen = listen(m_serverSocket, 10);//������������Ŀ
	if (num_listen == -1)
	{
		printf("listenʧ��! \n");
		isFail = -1;
	}
	printf("listen�ɹ���\n");
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
			printf("�ͻ�������ʧ�ܣ�\n");
			Server::~Server();
		}
		printf("�¿ͻ����룺%s\n", inet_ntoa(m_client_addr.sin_addr));
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)commuciation, (LPVOID)i, NULL, NULL);
	}

}










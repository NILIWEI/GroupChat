#include"client.h"
#pragma warning(disable:4996)

Client::Client(WSADATA wsaData, SOCKET serverSocket) :
	m_wsaData(wsaData)
{
	m_serverSocket = serverSocket;
}
Client::~Client()
{
	closesocket(m_serverSocket);//�رշ�����
	WSACleanup();//��������м���Ϣ
}
void Client::RequestProtocol()
{

	if (LOBYTE(m_wsaData.wVersion) != 2 || HIBYTE(m_wsaData.wVersion) != 2)
	{
		printf("����汾ʧ�ܣ�\n");
		isFail = -1;
	}
}


void Client::CreateSocket()
{

	if (m_serverSocket == -1)
	{
		printf("����Socketʧ�ܣ�\n");
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
		printf("���ӷ�����ʧ�ܣ�\n");
		isFail = -1;
	}

	//ѭ��ͨ��

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Recv_Show, NULL, NULL, NULL);

	char buffer[256];

	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		printf("��������Ϣ��");
		scanf("%s", buffer);
		r = send(m_serverSocket, buffer, strlen(buffer), NULL);//��������
		if (r > 0)
		{
			printf("\n����%d�ֽڵ��������ɹ���\n", r);
		}
	}

}

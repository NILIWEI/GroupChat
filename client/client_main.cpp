#include"client.h"

int main()
{
	initgraph(300,300,SHOWCONSOLE);
	WSADATA wsaData;//winsock��汾��Ϣ
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	Client client(wsaData, serverSocket);
	client.RequestProtocol();
	client.CreateSocket();
	client.CreateSocketAddr();
	client.LinkServer();
	if (client.getIsFail() < 0)
		return -1;
	printf("���ӷ������ɹ���\n");
	return 0;
}
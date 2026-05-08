#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <cstdlib>
#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32")

int main()
{
	WSAData wsaData;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//TCP, Stream
	SOCKET ListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN ListenSockAddr;
	//memset(&ListenSockAddr, 0, sizeof(ListenSocket));
	ZeroMemory(&ListenSockAddr, sizeof(ListenSocket));

	ListenSockAddr.sin_family = AF_INET;
	//ListenSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	inet_pton(AF_INET, "127.0.0.1", (PVOID)ListenSockAddr.sin_addr.s_addr);

	ListenSockAddr.sin_port = htons(20000);

	bind(ListenSocket, (SOCKADDR*)&ListenSockAddr, sizeof(ListenSockAddr));

	listen(ListenSocket, 0);


	SOCKADDR_IN ClientSockAddr;
	ZeroMemory(&ClientSockAddr, sizeof(ClientSockAddr));
	int ClientSockAddrLength = sizeof(ClientSockAddr);

	//accept´Â blocking ÇÔ¼ö
	SOCKET ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);





	closesocket(ListenSocket);

}
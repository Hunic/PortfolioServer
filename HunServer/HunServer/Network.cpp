#include "stdafx.h"
#include "Network.h"


CNetwork::CNetwork()
{
	std::cout << "CNetwork Constructor in" << std::endl;
	std::cout << "CNetwork Constructor out" << std::endl;
}


CNetwork::~CNetwork()
{
}
BOOL CNetwork::Init()
{
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 0);
	return TRUE;
}

//BOOL CNetwork::CreateListenSocket()
//{
//	
//}
//BOOL CNetwork::BindSocket()
//{
//	
//}
//BOOL CNetwork::ListenSocket()
//{
//	
//}
BOOL CNetwork::NetworkSetActivate()
{
	SOCKET ListenSocket;

	ListenSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	std::cout << "Socket 등록 완료" << std::endl;
	
	ZeroMemory(&listen_addr, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htonl((u_long)8000);
	ZeroMemory(&listen_addr.sin_zero, 8);

	ret = ::bind(ListenSocket,
		reinterpret_cast<sockaddr *>(&listen_addr),
		sizeof(listen_addr));
	if (SOCKET_ERROR == ret) {
		std::cout << "BIND 오류" << std::endl;
		exit(-1);
	}
	std::cout << "Bind Socket 등록 완료" << std::endl;
	

	ret = listen(ListenSocket, 10);
	if (SOCKET_ERROR == ret) {
		std::cout << "Listen 오류" << std::endl;
		exit(-1);
	}
	std::cout << "Listen Socket 등록 완료" << std::endl;
	return TRUE;
}

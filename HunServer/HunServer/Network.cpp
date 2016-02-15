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

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
	WSAStartup(MAKEWORD(2, 2), &m_wsadata);
	m_hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 0);
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
	return TRUE;
}

HANDLE CNetwork::GetIocpHandle()
{
	return m_hIOCP;
}
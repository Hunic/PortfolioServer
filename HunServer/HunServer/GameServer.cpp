#include "stdafx.h"
#include "GameServer.h"


CGameServer::CGameServer()
{
	std::cout << "CGameServer Constructor in" << std::endl;
	pNetwork = new CNetwork;
	pPacketProcess = new CPacketProcess;
	std::cout << "CGameServer Constructor out" << std::endl;
}


CGameServer::~CGameServer()
{
}

BOOL CGameServer::Init()
{
	std::cout << "Game Server Init In" << std::endl;
	return TRUE;
}
BOOL CGameServer::Activate()
{
	std::cout << "Game Server Activate In" << std::endl;
	return TRUE;
}
BOOL CGameServer::Shutdown()
{
	std::cout << "Game Server ShutDown In" << std::endl;
	return TRUE;
}

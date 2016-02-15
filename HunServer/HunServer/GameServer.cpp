#include "stdafx.h"
#include "GameServer.h"


CGameServer::CGameServer()
{
	std::cout << "CGameServer Constructor in" << std::endl;
	pNetwork = new CNetwork;
	pPacketProcess = new CPacketProcess;
	pThread = new CThread;
	std::cout << "CGameServer Constructor out" << std::endl;
}


CGameServer::~CGameServer()
{
}

BOOL CGameServer::Init()
{
	std::cout << "Game Server Init In" << std::endl;
	pNetwork->Init();
	std::cout << "Network Init Success" << std::endl;

	return TRUE;
}
BOOL CGameServer::Activate()
{
	std::cout << "Game Server Activate In" << std::endl;
	pThread->ResistThreads(THREAD_NUM);
	std::cout << "Threads Resist Threads Success" << std::endl;
	std::cout << "Game Server Activate Out" << std::endl;
	return TRUE;
}
BOOL CGameServer::Shutdown()
{
	std::cout << "Game Server ShutDown In" << std::endl;
	return TRUE;
}

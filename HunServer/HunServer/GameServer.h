#pragma once
#include "stdafx.h"
class CGameServer
{
	CNetwork* pNetwork;
	CPacketProcess* pPacketProcess;
public:
	CGameServer();
	~CGameServer();
	BOOL Init();
	BOOL Activate();
	BOOL Shutdown();
};


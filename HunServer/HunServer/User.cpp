#include "stdafx.h"
#include "User.h"


CUser::CUser()
{
}


CUser::~CUser()
{
}

void CUser::Init()
{
	int		m_nId = 0;
	bool	m_nIn_use = false;
	char*	m_cName = nullptr;
	int		m_nPos_x = 0;
	int		m_nPos_y = 0;
	int		m_nExp = 0;
	int		m_nLevelupExp = 0;
	int		m_nAtt_power = 0;
	int		m_nHp = 0;
	int		m_nMaxhp = 0;
	int		m_nMp = 0;
	int		m_nMaxmp = 0;
	int		m_nLevel = 0;
	int		m_nIs_alive = 0;
}
int CUser::GetId()
{
	return m_nId;
}
bool CUser::GetInused()
{
	return m_nIn_use;
}
char* CUser::GetName()
{
	return m_cName;
}
int CUser::GetXpos()
{
	return m_nPos_x;
}
int CUser::GetYpos()
{
	return m_nPos_y;
}
int CUser::GetExp()
{
	return m_nExp;
}
int CUser::GetLevelUpExp()
{
	return m_nLevelupExp;
}
int CUser::GetAttPower()
{
	return m_nAtt_power;
}
int CUser::GetHp()
{
	return m_nHp;
}
int CUser::GetMaxHp()
{
	return m_nMaxhp;
}
int CUser::GetMp()
{
	return m_nMp;
}
int CUser::GetMaxMp()
{
	return m_nMaxmp;
}
int CUser::GetLevel()
{
	return m_nLevel;
}
int CUser::GetIsAlive()
{
	return m_nIs_alive;
}
SOCKET CUser::GetSocket()
{
	return m_scSocket;
}

OVERLAPPED CUser::GetEXOVER_Overlapped()
{
	return m_exover_recv.m_Overlapped;
}

WSABUF CUser::GetEXOVER_Wsabuf()
{
	return m_exover_recv.m_Wsabuf;
}

char* CUser::GetEXOVER_Recvbuf()
{
	return m_exover_recv.m_cRecvbuf;
}

void CUser::SetId(int id)
{
	m_nId = id;
}
void CUser::SetInused(bool in_use)
{
	m_nIn_use = in_use;
}
void CUser::SetName(char* name)
{
	m_cName = name;
}
void CUser::SetXpos(int x)
{
	m_nPos_x = x;
}
void CUser::SetYpos(int y)
{
	m_nPos_y = y;
}
void CUser::SetExp(int Exp)
{
	m_nExp = Exp;
}
void CUser::SetLevelUpExp(int LevelupExp)
{
	m_nLevelupExp = LevelupExp;
}
void CUser::SetAttPower(int atkpower)
{
	m_nAtt_power = atkpower;
}
void CUser::SetHp(int hp)
{
	m_nHp = hp;
}
void CUser::SetMaxHp(int maxhp)
{
	m_nMaxhp = maxhp;
}
void CUser::SetMp(int mp)
{
	m_nMp = mp;
}
void CUser::SetMaxMp(int maxmp)
{
	m_nMaxmp = maxmp;
}
void CUser::SetLevel(int level)
{
	m_nLevel = level;
}
void CUser::SetIsAlive(int isalive)
{
	m_nIs_alive = isalive;
}
void CUser::SetSocket(SOCKET playersock)
{
	m_scSocket = playersock;
}

void CUser::SetEXOVER_Wsabuf_Buf(char* buf)
{
	m_exover_recv.m_Wsabuf.buf = buf;
}
void CUser::SetEXOVER_Wsabuf_Len(ULONG length)
{
	m_exover_recv.m_Wsabuf.len = length;
}

void CUser::SetEXOVER_Curr_packet_size(int packetSize)
{
	m_exover_recv.m_nCurr_packet_size = packetSize;
}

void CUser::SetEXOVER_Operation(int operation)
{
	m_exover_recv.m_nOperation = operation;
}
void CUser::SetEXOVER_StoredSize(int storesize)
{
	m_exover_recv.m_nStoredSize = storesize;
}

#pragma once
class CNetwork;

class CUser : public CNetwork
{
private:
	int		m_nId;
	bool	m_nIn_use;
	char*	m_cName;
	SOCKET	m_scSocket;
	int		m_nPos_x;
	int		m_nPos_y;
	int		m_nExp;
	int		m_nLevelupExp;
	int		m_nAtt_power;
	int		m_nHp;
	int		m_nMaxhp;
	int		m_nMp;
	int		m_nMaxmp;
	int		m_nLevel;
	int		m_nIs_alive;
	SRWLOCK m_rwlck;
	EXOVER	m_exover_recv;
public:
	CUser();
	~CUser();

	void	Init();

	int		GetId();
	bool	GetInused();
	char*	GetName();
	int		GetXpos();
	int		GetYpos();
	int		GetExp();
	int		GetLevelUpExp();
	int		GetAttPower();
	int		GetHp();
	int		GetMaxHp();
	int		GetMp();
	int		GetMaxMp();
	int		GetLevel();
	int		GetIsAlive();
	SOCKET	GetSocket();
	OVERLAPPED GetEXOVER_Overlapped();
	WSABUF	GetEXOVER_Wsabuf();
	char*	GetEXOVER_Recvbuf();



	void	SetId(int);
	void	SetInused(bool);
	void	SetName(char*);
	void	SetXpos(int);
	void	SetYpos(int);
	void	SetExp(int);
	void	SetLevelUpExp(int);
	void	SetAttPower(int);
	void	SetHp(int);
	void	SetMaxHp(int);
	void	SetMp(int);
	void	SetMaxMp(int);
	void	SetLevel(int);
	void	SetIsAlive(int);
	void	SetSocket(SOCKET);
	void	SetEXOVER_Wsabuf_Buf(char*);
	void	SetEXOVER_Wsabuf_Len(ULONG);
	void	SetEXOVER_Curr_packet_size(int);
	void	SetEXOVER_Operation(int);
	void	SetEXOVER_StoredSize(int);
};


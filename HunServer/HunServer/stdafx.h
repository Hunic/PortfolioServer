// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

//	Massage Type
enum msgType {
	RECV_msg = 1,
	SEND_msg,
	EVENT_msg
};
#include "Protocol.h"

//	Network Header
#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
//
#include "targetver.h"

//	I/O Basic Header
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <Windows.h>
//
#include <thread>
#include <chrono>
#include <mutex>



// Contaier Header
#include <vector>
#include <set>


// Extension Overlapped Struct
struct EXOVER {
	WSAOVERLAPPED m_Overlapped;
	WSABUF	 m_Wsabuf;
	int		 m_nOperation;
	char	 m_cRecvbuf[RECV_BUF_SIZE];
	char	 m_cPacketBuf[PACKET_BUF_SIZE];
	int      m_nCurr_packet_size;
	int      m_nStoredSize;
};




// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include "Network.h"
#include "Thread.h"
#include "PacketProcess.h"
#include "GameServer.h"
#include "User.h"





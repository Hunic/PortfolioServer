// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once
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






// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include "Protocol.h"
#include "Thread.h"
#include "Network.h"
#include "PacketProcess.h"
#include "GameServer.h"


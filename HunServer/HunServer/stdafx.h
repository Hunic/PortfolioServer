// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
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






// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include "Protocol.h"
#include "Thread.h"
#include "Network.h"
#include "PacketProcess.h"
#include "GameServer.h"


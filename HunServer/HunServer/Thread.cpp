#include "stdafx.h"
#include "Thread.h"

CUser cPlayer[MAX_USER_NUM];
CThread::CThread()
{
}


CThread::~CThread()
{
}
VOID CThread::ResistThreads(const int threadNum)
{
	//Acept Thread Resist
	accept_thread = std::thread{ std::mem_fun(&CThread::AcceptThread),this };
	std::cout << "Accept Thread ��� �Ϸ�" << std::endl;
	//Worker Thread ���
	for (int i = 0; i < threadNum; ++i)
	{
		worker_thread.push_back(new std::thread{ std::mem_fun(&CThread::WorkerThread),this });
		std::cout << i + 1 << "��° Thread ����, �Լ� ��� �Ϸ�" << std::endl;
	}
	


}
VOID CThread::WorkerThread()
{
	std::cout << "Worker_thread ó�� �Լ� ����" << std::endl;
	
	DWORD io_size;
	int id;
	EXOVER *overlapped;

	while (true) {
		int ret = GetQueuedCompletionStatus(CNetwork::GetIocpHandle(), &io_size, (PULONG_PTR)&id, reinterpret_cast<LPOVERLAPPED *>(&overlapped), INFINITE);

		if (io_size == 0 || io_size == 0) {
			if (ret == 0)
			{
				DWORD temp1, temp2;
				WSAGetOverlappedResult(cPlayer[id].GetSocket(), &overlapped->m_Overlapped,
					&temp1, FALSE, &temp2);
				std::cout << "�������� Result ����" << std::endl;
			}

			//closesocket(players[id].my_socket);
			continue;
		}

		if (overlapped->m_nOperation == RECV_msg) {
			//int rest = io_size;
			//CHAR *buf = overlapped->m_cRecvbuf;
			//int packet_size = overlapped->m_nCurr_packet_size;
			//int old_received = overlapped->m_nStoredSize;

			//while (0 != rest) {
			//	if (0 == packet_size) packet_size = buf[0];
			//	int required = packet_size - old_received;
			//	if (rest >= required) {  // ��Ŷ ���� ����
			//		memcpy(overlapped->m_cPacketBuf + old_received,
			//			buf, required);
			//		//pPacketProcess->PacketProcess(id, overlapped->m_cPacketBuf);
			//		packet_size = 0;
			//		old_received = 0;
			//		buf += required;
			//		rest -= required;
			//	}
			//	else { // ��Ŷ�� �ϼ��ϱ⿡�� ����Ÿ�� ����
			//		memcpy(overlapped->m_cPacketBuf + old_received,
			//			buf, rest);
			//		old_received += rest;
			//		rest = 0;
			//	}
			//} // ��Ŷ ���� while ����
			//overlapped->m_nCurr_packet_size = packet_size;
			//overlapped->m_nStoredSize = old_received;
			//DWORD recv_flag = 0;
			//int ret = WSARecv(cPlayer[id].GetSocket(),
			//	&cPlayer[id].GetEXOVER_Wsabuf(), 1,
			//	NULL, &recv_flag,
			//	&cPlayer[id].GetEXOVER_Overlapped(), NULL);

			//if (ret) {	// WSAENOTSOCK
			//	
			//}
		}
		else if (overlapped->m_nOperation == SEND_msg) {
			delete overlapped;
		}
		else if (overlapped->m_nOperation == EVENT_msg)
		{
			//�߰�������ϴºκ�
		}
		else {
			printf("Error invalid overlapped\n");
			exit(-1);
		}
	}
}
VOID CThread::AcceptThread()
{
	struct sockaddr_in listen_addr;
	struct sockaddr_in client_addr;

	SOCKET ListenSocket;

	ListenSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	std::cout << "Socket ��� �Ϸ�" << std::endl;

	ZeroMemory(&listen_addr, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htonl(SERVERPORT);
	ZeroMemory(&listen_addr.sin_zero, 8);

	int ret = ::bind(ListenSocket,
		reinterpret_cast<sockaddr *>(&listen_addr),
		sizeof(listen_addr));
	if (SOCKET_ERROR == ret) {
		std::cout << "BIND ����" << std::endl;
		exit(-1);
	}
	std::cout << "Bind Socket ��� �Ϸ�" << std::endl;


	ret = listen(ListenSocket, 10);
	if (SOCKET_ERROR == ret) {
		std::cout << "Listen ����" << std::endl;
		exit(-1);
	}
	std::cout << "Listen Socket ��� �Ϸ�" << std::endl;
	//return TRUE;
	int addr_size = sizeof(client_addr);
	while (true) {
		SOCKET client_socket = WSAAccept(ListenSocket,
			reinterpret_cast<sockaddr *>(&client_addr),
			&addr_size, NULL, NULL);


		int id = 0;
		cPlayer[id].SetId(TRUE);
		cPlayer[id].SetSocket(client_socket);
		cPlayer[id].SetXpos(0);
		cPlayer[id].SetYpos(0);
		std::cout << " xpos: " << cPlayer[id].GetXpos() << " ypos : " << cPlayer[id].GetYpos() << std::endl;
		cPlayer[id].SetEXOVER_Curr_packet_size(0);
		cPlayer[id].SetEXOVER_Operation(msgType::RECV_msg);
		ZeroMemory(&cPlayer[id].GetEXOVER_Overlapped(), sizeof(WSAOVERLAPPED));
		cPlayer[id].SetEXOVER_StoredSize(0);
		//cPlayer[id].view_list.clear();
		// IOCP ����
		CreateIoCompletionPort(reinterpret_cast<HANDLE>(client_socket),
			CNetwork::GetIocpHandle(), id, 0);
		// Recvȣ��
		unsigned long recv_flag = 0;
		int ret = WSARecv(client_socket,
			&cPlayer[id].GetEXOVER_Wsabuf(), 1, NULL, &recv_flag,
			&cPlayer[id].GetEXOVER_Overlapped(), NULL);
		if (ret) {
			// WSAENOTSOCK
			int err_code = WSAGetLastError();
			if (err_code != ERROR_IO_PENDING)
				printf("Recv Error [%d]\n", err_code);
		}
	}
}

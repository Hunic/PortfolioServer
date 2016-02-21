#pragma once

class CThread : public CNetwork
{
	
	//SOCKET ListenSocket;
	std::vector<std::thread*> worker_thread;
	std::thread accept_thread;
	
public:
	
	CThread();
	~CThread();
	VOID ResistThreads(const int);
	VOID WorkerThread();
	VOID AcceptThread();
};


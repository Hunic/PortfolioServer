#pragma once
class CThread
{
	std::vector<std::thread*> worker_thread;
public:
	CThread();
	~CThread();
	VOID ResistThreads(const int);
	VOID WorkerThread();
};


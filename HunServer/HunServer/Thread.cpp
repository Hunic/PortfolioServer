#include "stdafx.h"
#include "Thread.h"


CThread::CThread()
{
}


CThread::~CThread()
{
}
VOID CThread::WorkerThread()
{

}
VOID CThread::ResistThreads(const int threadNum)
{
	//Worker Thread µî·Ï
	for (int i = 0; i < threadNum; ++i)
	{
		worker_thread.push_back(new std::thread{ std::mem_fun(&CThread::WorkerThread),this });
	}
}
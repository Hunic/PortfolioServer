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
VOID CThread::AcceptThread()
{
	CNetwork* pNetwork = new CNetwork;
	pNetwork->NetworkSetActivate();
}
VOID CThread::ResistThreads(const int threadNum)
{
	//Worker Thread ���
	for (int i = 0; i < threadNum; ++i)
	{
		worker_thread.push_back(new std::thread{ std::mem_fun(&CThread::WorkerThread),this });
		std::cout << i + 1 << "��° Thread ����, �Լ� ��� �Ϸ�" << std::endl;
	}
	//Acept Thread Resist
	accept_thread = std::thread{ std::mem_fun(&CThread::AcceptThread),this };
	std::cout << "Accept Thread ��� �Ϸ�" << std::endl;
	
}
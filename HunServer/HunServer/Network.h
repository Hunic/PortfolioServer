#pragma once
class CNetwork
{
	WSADATA m_wsadata;
	HANDLE m_hIOCP;
	
	


	int ret;
	
public:
	

	CNetwork();
	~CNetwork();
	BOOL Init();
	BOOL NetworkSetActivate();

	HANDLE GetIocpHandle();
	

};


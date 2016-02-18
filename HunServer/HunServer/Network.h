#pragma once
class CNetwork
{
	WSADATA wsadata;
	HANDLE hIOCP;
	
	struct sockaddr_in listen_addr;
	struct sockaddr_in client_addr;

	int ret;
	
public:
	

	CNetwork();
	~CNetwork();
	BOOL Init();
	BOOL NetworkSetActivate();
	

};


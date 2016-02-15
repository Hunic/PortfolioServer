#pragma once
class CNetwork
{
	WSADATA wsadata;
	HANDLE hIOCP;
	
public:
	CNetwork();
	~CNetwork();
	BOOL Init();
	

};


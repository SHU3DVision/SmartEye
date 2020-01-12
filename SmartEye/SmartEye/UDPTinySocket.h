#pragma once

class UTinySocket
{
public:
	UTinySocket(int server = 0, int port = 0);
	//CTinySocket();
	~UTinySocket();
	int	Sendto( const char* destip, const int destport, char* buf, int bufsize  );
	int Recvfrom(char* buf, int bufsize, char hostip[], int &hostport);
	char udp_ip[128];
	int port;

private:
	int  sockfd;
	int  sk_master;
	int  sk_slave;
	int  my_port;
	
};

extern "C" void udp_startup(void); //extern "C"是实现的类C和C++的混合编程
extern "C" void udp_cleanup(void);
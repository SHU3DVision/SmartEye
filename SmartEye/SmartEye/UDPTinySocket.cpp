#include <iostream>
#include <WINSOCK2.H>
#include <WS2tcpip.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")
#include "UDPTinySocket.h"


void udp_startup(void)
{
	static int wsa_started;
	if (!wsa_started)
	{
		WSADATA wd;
		WSAStartup(0x0202, &wd);
		wsa_started = 1;
	}
}
void udp_cleanup(void)
{
	WSACleanup();

}

static void set_blocking(int fd, int blocking)
{
	u_long sock_flags;
	sock_flags = !blocking;
	int ret = ioctlsocket(fd, FIONBIO, (u_long*)&sock_flags);
}

UTinySocket::UTinySocket(int server, int port)
{
	udp_startup();
	sockfd = -1;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (server)
	{
		DWORD tv = 30000;
		int nRecvBuf = 209715200;

		static struct sockaddr_in servaddr = { 0 };		
		if (sockfd != -1)
		{
			//设置IP和端口
			servaddr.sin_family = AF_INET;
			servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
			servaddr.sin_port = htons(port);
			//绑定
			bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
			//设置接收超时时间
			setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
			//设置缓冲区大小
			setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (const char *)&nRecvBuf, sizeof(nRecvBuf));
			set_blocking(sockfd, 0);
		}

	}

	//	//广播且非阻塞
	//	// Enable broadcast
	//	//setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (const char*)&one, sizeof(one));
	
}


UTinySocket::~UTinySocket()
{
	closesocket(sockfd);
	udp_cleanup();
}


int	UTinySocket::Sendto(const char* destip, const int destport, char* buf, int bufsize)
{
	struct sockaddr_in socketinfo;
	int ip_valid = 0;
	socketinfo.sin_family = AF_INET;
	socketinfo.sin_addr.s_addr = inet_addr(destip);
	socketinfo.sin_port = htons(destport);

	ip_valid = socketinfo.sin_addr.s_addr != INADDR_NONE;
	if (!ip_valid)
	{
		return 0;
	}
	socketinfo.sin_family = AF_INET;
	socketinfo.sin_port = htons(destport);

	int n = sendto(sockfd, buf, bufsize, 0, (struct sockaddr *) &socketinfo, sizeof(socketinfo));//向地址发送buf数据

	return n;
}

//UDP读取数据
//buf 接收到的数据指针
//bufsize 期望接收到的长度
//hostip 发送方ip
//hostport 发送方端口
//返回 实际接收到的长度
int UTinySocket::Recvfrom(char* buf, int bufsize, char hostip[], int &hostport)
{
	struct sockaddr_in addr = { 0 };
	int struct_len = sizeof(addr);
	
	int n = recvfrom(sockfd, buf, bufsize, 0, (struct sockaddr *)&addr, (socklen_t *)&struct_len);//n为接受的字符数组的长度

	//en = recvfrom(sockfd, recvline, 512, 0, (struct sockaddr *) &ca, (socklen_t *)&struct_len);  //接受数据-------正确写法

	if (n > 0)
	{
		char* hip = inet_ntoa(addr.sin_addr);
		strcpy(hostip, hip);
		hostport = htons(addr.sin_port);
	}

	
	return n;
}

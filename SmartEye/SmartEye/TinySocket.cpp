#include <WINSOCK2.H>
#include <WS2tcpip.h>
#include <stdio.h>
#include "smarteye.h"
#pragma comment(lib,"ws2_32.lib")
#include "TinySocket.h"



void sk_startup(void)
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
}
void sk_cleanup(void)
{
	//终止使用 DLL
	WSACleanup();
}
int CTinySocket:: socket_com(char sendline[], int length, const char* destip, const int destport)
{
	//socket connect
	sk_startup();
	char* ptr_buf = buf;
	int count = 0;
	int rec_len, Ret;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == INVALID_SOCKET)
	{
		return 0;
		exit(0);
	}
	else
	{
	  
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(destport);
	servaddr.sin_addr.s_addr = inet_addr(destip);
	Ret = connect(sockfd, (SOCKADDR*)&servaddr, sizeof(servaddr));
	if (Ret == SOCKET_ERROR)
	{
		return 0;
		exit(0);
	}

	else
	{
		
	}
	Ret = send(sockfd, sendline, strlen(sendline), 0);
	if (Ret == SOCKET_ERROR)
	{
		return 0;
		exit(0);
	}
	else
	{
		
	}
	int i2 = 0;
	while (count < length) //153600
	{
		rec_len = recv(sockfd, buf, MAXLINE, 0);
		for (int i = 0; i < rec_len; i++)
		{

			ptr_buf2[i2] = buf[i];
			i2++;

		}
		if (rec_len == SOCKET_ERROR)
		{
			cout << "接受Error::" << GetLastError() << endl;
			exit(0);
		}

		count = count + rec_len;

	}
	//关闭套接字
	closesocket(sockfd);
	//终止使用 DLL
	sk_cleanup();
	return 1;
}

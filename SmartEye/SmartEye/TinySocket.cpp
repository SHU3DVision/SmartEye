#include "TinySocket.h"
#include <WINSOCK2.H>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

CTinySocket::CTinySocket()
{

}
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
//socket获取图像
//sendline[] 发送指令
// length 期待获取的长度
// destip 相机ip
//destport 相机端口号
//返回：成功后返回1
//      失败后返回0
int CTinySocket:: socket_com(char sendline[], int length, const char* destip, const int destport)
{
	//socket connect
	sk_startup();
	char* ptr_buf = buf;
	int count = 0;             //接收总字节计数
	int rec_len, Ret;          //发送、接收状态
	static struct sockaddr_in servaddr;

	//socket初始化
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == INVALID_SOCKET)
	{
		return 0;
		exit(0);
	}
	else
	{
	  
	}
	//设置相机IP信息
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(destport);
	servaddr.sin_addr.s_addr = inet_addr(destip);
	//连接相机
	Ret = connect(sockfd, (SOCKADDR*)&servaddr, sizeof(servaddr));
	if (Ret == SOCKET_ERROR)
	{
		return 0;
		exit(0);
	}

	else
	{
		
	}
	//发送采集命令
	Ret = send(sockfd, sendline, strlen(sendline), 0);
	if (Ret == SOCKET_ERROR)
	{
		return 0;
		exit(0);
	}
	else
	{
		
	}
	//接收返回图像数据
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
			//cout << "接受Error::" << GetLastError() << endl;
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
CTinySocket::~CTinySocket()
{
	

}
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
	//��ֹʹ�� DLL
	WSACleanup();
}
//socket��ȡͼ��
//sendline[] ����ָ��
// length �ڴ���ȡ�ĳ���
// destip ���ip
//destport ����˿ں�
//���أ��ɹ��󷵻�1
//      ʧ�ܺ󷵻�0
int CTinySocket::socket_com(char sendline[], int length, const char* destip, const int destport, char* buf)
{
	//socket connect
	sk_startup();
	char tempbuf[MAXBUFLINE];      //���ջ�����
	int count = 0;             //�������ֽڼ���
	int rec_len, Ret;          //���͡�����״
	static struct sockaddr_in servaddr;
	databuf = buf;
	//socket��ʼ��
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == INVALID_SOCKET)
	{
		sk_cleanup();
		return -1;
		
	}
	else
	{
	  
	}
	//�������IP��Ϣ
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(destport);
	servaddr.sin_addr.s_addr = inet_addr(destip);
	//������ģʽ
	u_long imode = 1;
	if (ioctlsocket(sockfd, FIONBIO, &imode) == SOCKET_ERROR)
	{
		int err = WSAGetLastError();
		closesocket(sockfd);
		sk_cleanup();
		return -1;
	}
	struct timeval tm;
	tm.tv_sec = 5;
	tm.tv_usec = 0;
	//�������
	Ret = connect(sockfd, (SOCKADDR*)&servaddr, sizeof(servaddr));
	if (Ret == SOCKET_ERROR)
	{
		fd_set set;
		FD_ZERO(&set);
		FD_SET(sockfd, &set);
		if (select(-1,NULL,&set,NULL,&tm) <= 0)
			return -1;
	}
	else
	{
		
	}

	//���û�����
	u_long imodeb = 0;
	if (ioctlsocket(sockfd, FIONBIO, &imodeb) == SOCKET_ERROR)
	{
		int err = WSAGetLastError();
		switch (err)
		{
		case WSANOTINITIALISED: qDebug() << "WSANOTINITIALISED"; break;
		case WSAENETDOWN: qDebug() << "WSAENETDOWN"; break;
		case WSAEINPROGRESS: qDebug() << "WSAEINPROGRESS"; break;
		case WSAENOTSOCK: qDebug() << "WSAENOTSOCK"; break;
		case WSAEFAULT:	qDebug() << "WSAEFAULT"; break;
		default:
			break;
		}
		return -1;
	}

	//���Ͳɼ�����
	Ret = send(sockfd, sendline, strlen(sendline), 0);
	if (Ret == SOCKET_ERROR)
	{
		return -1;
		
	}
	else
	{
		
	}
	int i2 = 0;
	//getDistanceSorted getDistanceAndAmplitudeSorted
	if ((strcmp(sendline,"getDistanceSorted")==0)||(strcmp(sendline, "getDistanceAndAmplitudeSorted") == 0))
	{
		//���շ���ͼ������
		
		while (count < length) //153600 307200
		{
			rec_len = recv(sockfd, tempbuf, MAXBUFLINE, 0);
			for (int i = 0; i < rec_len; i++)
			{

				buf[i2] = tempbuf[i];
				i2++;

			}
			if (rec_len == SOCKET_ERROR)
			{
				
			}

			count = count + rec_len;

		}
	}
	else if (strcmp(sendline,"getTemperature")==0)
	{
		//����¶�
		rec_len = recv(sockfd, tempbuf, MAXBUFLINE, 0);
		for (int i = 0; i < rec_len; i++)
		{

			buf[i2] = tempbuf[i];
			i2++;

		}
		if (rec_len == SOCKET_ERROR)
		{
			return -1;
		}
		
	}
	else 
	{
		//����ָ��
		rec_len = recv(sockfd, tempbuf, MAXBUFLINE, 0);
		/*qDebug() << "-------------------" << rec_len;
		qDebug() << "-------------------" << tempbuf;*/
		if (rec_len == SOCKET_ERROR)
		{
			return -1;
		}
		for (int i = 0; i < rec_len; i++)
		{
			buf[i] = tempbuf[i];
		}
	}
	
	//�ر��׽���
	closesocket(sockfd);
	//��ֹʹ�� DLL
	sk_cleanup();
	if ((strcmp(sendline, "getDistanceSorted") == 0) || strcmp(sendline, "getDistanceAndAmplitudeSorted") == 0)
	{
		return 1;
	}
	else if (strcmp(sendline, "getTemperature") == 0)
	{
		return rec_len;
	}
	else
	{
		return 0;
	}
	
}
CTinySocket::~CTinySocket()
{
	

}
//��ȡ�������
void CTinySocket::receive_depth()
{

}
//��ȡ�¶�����
void CTinySocket::receive_temperature()
{
}
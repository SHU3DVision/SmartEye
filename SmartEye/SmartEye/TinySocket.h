#pragma once

#include <stdio.h>
#include<string>
#include<iostream>
#include<qdebug.h>


#define MAXBUFLINE 307200


using namespace std;
class CTinySocket
{
 public:
	 CTinySocket();
	 ~CTinySocket();
	 int socket_com(char sendline[], int length, const char* destip, const int destport, char* buf);
	 void receive_depth();
	 void receive_temperature();
	 int _port;          
	 string _ip;
private:
	int  sockfd;
	int	 g_TempReadDelay = 0;	//��ȡ�¶ȼ�ʱ
	int g_TempReadEnable=1;		//��ȡ�¶ȱ�ʾ
	int	realTempChip;		//�¶�
	int	realTempBoard1;
	int	realTempBoard2;
	char *databuf;
	
};
extern "C" void sk_startup(void); //extern "C"��ʵ�ֵ���C��C++�Ļ�ϱ��
extern "C" void sk_cleanup(void);
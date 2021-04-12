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
	int	 g_TempReadDelay = 0;	//获取温度计时
	int g_TempReadEnable=1;		//获取温度标示
	int	realTempChip;		//温度
	int	realTempBoard1;
	int	realTempBoard2;
	char *databuf;
	
};
extern "C" void sk_startup(void); //extern "C"是实现的类C和C++的混合编程
extern "C" void sk_cleanup(void);

#include <stdio.h>
#include<string>
#include<iostream>


#define MAXLINE 253600
#define MAX_NUM_PIX	82656	//328 * 252
#define LOW_AMPLITUDE 	32500
#define MAX_PHASE        30000.0
#define MAX_DIST_VALUE 	30000
#define offsetPhaseDefault 0

using namespace std;
class CTinySocket
{
 public:
	 CTinySocket();
	 ~CTinySocket();
	 int socket_com(char sendline[], int length,const char* destip,const int destport);
	 char buf[MAXLINE];      //接收缓冲区
	 char ptr_buf2[MAXLINE];  //存储缓存区
	 int _port;          
	 string _ip;
private:
	int  sockfd;
	
};
extern "C" void sk_startup(void); //extern "C"是实现的类C和C++的混合编程
extern "C" void sk_cleanup(void);
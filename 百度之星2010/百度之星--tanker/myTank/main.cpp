//Astar 2010 坦克大战
//main.cpp 
//请勿修改此代码文件 

#pragma comment(lib,"ws2_32.lib") 

#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include "Tank.h"

int main(int argc,char *argv[])
{
	char recvBuf[sizeof(DataForAI)+1];
	char sendBuf[128];
	
    if (argc!=2)
	{
        return 1;
    }
   	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD( 1, 1 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) 
	{
		return 1;
	}
	if ( LOBYTE( wsaData.wVersion ) != 1 || HIBYTE( wsaData.wVersion ) != 1 ) 
	{
			WSACleanup( );
			return 1;
	}
	SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(atoi(argv[1]));
	if (bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR))<0)
    {
    	MessageBox(NULL,TEXT("端口已被其他程序绑定。请检查是否启用了另一个同色AI。"),"错误", MB_ICONERROR);
        return 1;                                                         
    }
	listen(sockSrv,1);
	SOCKADDR_IN addrClient;
	int len=sizeof(SOCKADDR);
	printf("AI Startup.\n");

	while(1)
	{
        int recv_len=0;
		SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);
		recv_len=recv(sockConn,recvBuf,sizeof(DataForAI),0);
        while (recv_len<sizeof(DataForAI))
        {
            Sleep(16);
            recv_len+=recv(sockConn,recvBuf+recv_len,sizeof(DataForAI)-recv_len,0);
        }
		if (strcmp(recvBuf,"Exit")==0)
		{
			break;
		}
		if (strcmp(recvBuf,"Initiate_red")==0)
		{
			*(InitiateInfo *)sendBuf = chooseType();
			printf("Red AI verified. Name:%s\n",((InitiateInfo *)sendBuf)->aiName);
		}
		else 
			if (strcmp(recvBuf,"Initiate_blue")==0)
			{
				*(InitiateInfo *)sendBuf = chooseType();
				printf("Blue AI verified. Name:%s\n",((InitiateInfo *)sendBuf)->aiName);
		     }
			else
			{
				*(Order *)sendBuf = makeOrder(*(DataForAI *)recvBuf);
            }
		Sleep(32);
        int send_len=send(sockConn,(const char *)(sendBuf),128,0);
        closesocket(sockConn);

	}
	return 0;      
}

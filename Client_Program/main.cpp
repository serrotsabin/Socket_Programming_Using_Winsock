
#include <stdio.h>
#include<iostream>

#include "winsock2.h"
using namespace std;
int main()
{

//	Initialize Winsock.
    WSADATA wsaData;

    int iResult = WSAStartup( MAKEWORD(2,2), &wsaData );
    if ( iResult != NO_ERROR )
        printf("Error at WSAStartup()\n");

//	Create a socket.

    SOCKET m_socket;

    m_socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

    if ( m_socket == INVALID_SOCKET )
    {

        printf( "Error at socket(): %ld\n", WSAGetLastError() );
        WSACleanup();
        return 0;
    }

//	Connect to a server.

    sockaddr_in clientService;

    clientService.sin_family = AF_INET;

    //clientService.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    clientService.sin_addr.s_addr = inet_addr( "192.168.137.1" );
    clientService.sin_port = htons( 27015 );
    cout<<"\nTrying to connect";


    if ( connect( m_socket, (SOCKADDR*) &clientService, sizeof(clientService) ) == SOCKET_ERROR)
       {printf( "\nFailed to connect.\n" );
       int c;
       scanf("%d",&c);
       }
    else
    {
    printf("\nYou Are Now Connected To The Server\n");

    int bytesSent;
    int bytesRecv = SOCKET_ERROR;
    char sendbuf[100] = "Client Requesting";
    char recvbuf[100] = "";

    bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );
    printf("\nClient Requesting\n");
    printf( "Bytes Sent: %ld\n", bytesSent );
    bytesRecv = recv( m_socket, recvbuf, 100, 0 );
    printf( "Bytes Recv: %ld\n", bytesRecv );
    cout<<recvbuf;
    printf("\n\n");
        int i;
        for (i=0;i=9;++i){
        std::fill(&recvbuf[0], &recvbuf[100], 0);
        bytesRecv = recv( m_socket, recvbuf, 100, 0 );
        printf( "\nBytes Recv: %ld", bytesRecv );
        cout<<"\nMessage Server:"<<recvbuf;
        printf("\n\n");

        std::fill(&sendbuf[0], &sendbuf[100], 0);
        cout<<"\nMessage Client: ";
        cin>>sendbuf;
        bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );
        printf( "Bytes Sent: %ld\n", bytesSent );
        }
    /*while( bytesRecv == SOCKET_ERROR )
    {

        bytesRecv = recv( m_socket, recvbuf, 100, 0 );

        if ( bytesRecv == 0 || bytesRecv == WSAECONNRESET )
        {
            printf( "Connection Closed.\n");

            break;
        }
        if (bytesRecv < 0)
            return 0;
        printf( "Bytes Recv: %ld\n", bytesRecv );
        cout<<"\n\n:Message Server:"<<recvbuf;

        //printf( "Message s\n", bytesRecv );
    }
*/
/*
    bytesRecv = recv( m_socket, recvbuf, 100, 0 );
    //printf( "Bytes Recv: %ld\n", bytesRecv );
        cout<<"\n\t:Message Server:"<<recvbuf;


        cout<<"\nEnter the message you want to send: ";
cin>>sendbuf;
bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );

cout<<"\nMessage Client:\t ";
cin>>sendbuf;
bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );

bytesRecv = recv( m_socket, recvbuf, 100, 0 );
    //printf( "Bytes Recv: %ld\n", bytesRecv );
        cout<<"\n:Message Server:"<<recvbuf;


cout<<"\nMessage Client:\t ";
cin>>sendbuf;
bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );
*/

}
int b;
scanf("%d",&b);
WSACleanup();
return 0;

}


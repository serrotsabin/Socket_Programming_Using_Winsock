#include <stdio.h>
#include<iostream>

#include "winsock2.h"
using namespace std;

int main() {

//	Initialize Winsock.
WSADATA wsaData;

int iResult = WSAStartup( MAKEWORD(2,2), &wsaData ); if ( iResult != NO_ERROR )
printf("Error at WSAStartup()\n");

//	Create a socket.

SOCKET m_socket;

m_socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

if ( m_socket == INVALID_SOCKET ) {

printf( "Error at socket(): %ld\n", WSAGetLastError() );
WSACleanup();
return 0;
}

//	Bind the socket.
sockaddr_in service;

service.sin_family = AF_INET;

service.sin_addr.s_addr = inet_addr( "192.168.137.1" ); service.sin_port = htons( 27015 );
//service.sin_addr.s_addr = inet_addr( "127.0.0.1" ); service.sin_port = htons( 27015 );

if ( bind( m_socket, (SOCKADDR*) &service, sizeof(service) ) == SOCKET_ERROR ) { printf( "bind() failed.\n" );
closesocket(m_socket);

}

// Listen on the socket.

if ( listen( m_socket, 1 ) == SOCKET_ERROR ) printf( "Error listening on socket.\n");

//	Accept connections.
SOCKET AcceptSocket;

printf( "Waiting for a client to connect...\n" ); while (1) {
AcceptSocket = SOCKET_ERROR;
while ( AcceptSocket == SOCKET_ERROR ) { AcceptSocket = accept( m_socket, NULL, NULL );
}
printf( "Client Connected.\n");
m_socket = AcceptSocket;
break;
}

//	Send and receive data.
int bytesSent;
int bytesRecv = SOCKET_ERROR;

char recvbuf[100] = "";
bytesRecv = recv( m_socket, recvbuf, 100, 0 );
cout<<recvbuf;
printf( "\nBytes Recv: %ld", bytesRecv );
printf("\nSuccessfully sent and Received Data\n");
char sendbuf[100] = "OK";
bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );
printf( "Bytes Sent: %ld\n", bytesSent );

int i;
        for (i=0;i=9;++i){

std::fill(&sendbuf[0], &sendbuf[100], 0);
cout<<"\n\n\nMessage Server: ";
cin>>sendbuf;
bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );
printf( "Bytes Sent: %ld\n", bytesSent );

std::fill(&recvbuf[0], &recvbuf[100], 0);
bytesRecv = recv( m_socket, recvbuf, 100, 0 );
printf( "\nBytes Recv: %ld", bytesRecv );
cout<<"\nMessage Client: "<<recvbuf;

        }
//cout<<"\n Hello;- Message from the Server";;
//cout<<"\n The message from the server:\n\n\n\t";
//cout<<recvbuf;



/*cout<<"Enter the message you want to send";
cin>>sendbuf;
bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );

 bytesRecv = recv( m_socket, recvbuf, 100, 0 );
    printf( "\t Bytes Recv: %ld\n", bytesRecv );
        cout<<"\n\t:Message Client: "<<recvbuf;
*/
/*bytesRecv = recv( m_socket, recvbuf, 100, 0 );
    printf( "\nBytes Recv: %ld\n", bytesRecv );
        cout<<"\n:Message Client: "<<recvbuf;

cout<<"Message Server:\t";
cin>>sendbuf;
bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );

 bytesRecv = recv( m_socket, recvbuf, 100, 0 );
    printf( "\t Bytes Recv: %ld\n", bytesRecv );
        cout<<"\n:Message Client: "<<recvbuf;
*/

int a;
scanf("%d",&a);
}


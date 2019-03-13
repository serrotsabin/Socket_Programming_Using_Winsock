#include <iostream>
#include<string>

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
#include<winsock.h>
using namespace std;
int main() {

 SOCKET m_socket;
 WSADATA wsaData;
        int iResult = WSAStartup( MAKEWORD(2,2), &wsaData );
        if ( iResult != NO_ERROR )
            printf("Error at WSAStartup()\n");


        // alsaasdfasCreate a socket.

        m_socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
        if ( m_socket == INVALID_SOCKET ) {
            printf( "Error at socket(): %ld\n", WSAGetLastError() );
            WSACleanup();
            return 99;
        }


        // Connect to a server.
        sockaddr_in clientService;
        clientService.sin_family = AF_INET;

        char serverIp[40] ="192.168.137.1";
      string userServerIp="";

        cout<<"\nTrying Initalizing the clinet:-";
        cout<<"\n Do you want to enter the Ip Address:Host Ip address [Y/N]\n";
        char usr ='5';

        //cin>>usr;
        if(usr=='y'|| usr=='Y') {

            cout<<"\n Please enter  IPaddress of Server you are connected through Wifi-hotspot\n";
            cin>>userServerIp;
            //cout<<"\n...Setting the IP address of the Host";

            strcpy(serverIp, userServerIp.c_str());
            cout<<"\n Entering "<<serverIp<<" as the Local Host\n\n";

        } else {
            cout<<"\nyou opted to run on Default Ip address set by program itself "<<serverIp;
            //serverIp = "192.168.137.1";
        }
        clientService.sin_addr.s_addr = inet_addr( "192.168.137.1" );
        clientService.sin_port = htons( 27015 );
        if ( connect( m_socket, (SOCKADDR*) &clientService, sizeof(clientService) ) == SOCKET_ERROR) {
            printf( "\nFailed to connect.\n" );
            cout<<"\nSorrry.... Right now, No Server is Listening at IPAddress you entered";
            cout<<"\n Terminating the Game in 10 Secs...Please allow the FIREWALL to use TCP/IP??";
            //delay(10000);
            WSACleanup();
            return 88;
        }
    }
//*/

    // Send and receive data.
    //int bytesSent;
    /*
    int bytesRecv = SOCKET_ERROR;
    char sendbuf[50] = "This is client";
    char recvbuf[50] = "";
    int bytesSent = send( m_socket, sendbuf, strlen(sendbuf), 0 );
    printf( "Bytes Sent: %ld\n", bytesSent );
    while( bytesRecv == SOCKET_ERROR )
    {
    bytesRecv = recv( m_socket, recvbuf, 32, 0 );
    if ( bytesRecv == 0 || bytesRecv == WSAECONNRESET )
    {
        printf( "Connection Closed.\n");
        break;
    }
    if (bytesRecv < 0)
        return 77;
    printf( "Bytes Recv: %ld\n", bytesRecv );

    ////cout<<"\n The message received is:"<<recvbuf;
    */



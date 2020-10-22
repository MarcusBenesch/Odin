#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main( int argc, char* argv[])
{
    int s;
    int len;
    char buffer[256];
    char returnedBuff[512];
    struct sockaddr_in servAddr;
    struct sockaddr_in cliAddr;
    int cliAddrlen;
    int servPort;
    

    if(argc != 3)
    {
        printf("Error: two arguments are needed!");
        //printf("There were %d arguments", argc -1);
        exit(1);
    }
    servPort = atoi(argv[1]);

    memset(&servAddr,0,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(servPort);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);


    if((s = socket(PF_INET,SOCK_DGRAM, 0))<0)
    {
        perror("Error: socket failed!");
        exit(1);
    }
    if((bind(s, (struct sockaddr*)& servAddr, sizeof(servAddr))<0))
    {
        perror("Error: bind failed");
        exit(1);
    }
    while(1)
    {
        memset(returnedBuff,0,strlen(returnedBuff));
        len = recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliAddr, &cliAddrlen);
        strcpy(returnedBuff, buffer);
        strcat(returnedBuff, argv[2]);
        printf("buffer = %s\n ", returnedBuff);
        sendto(s, returnedBuff, strlen(returnedBuff) , 0, (struct sockaddr*)&cliAddr, sizeof(cliAddr));
        memset(returnedBuff,0,strlen(returnedBuff)); 
    
    }
}
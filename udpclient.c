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
    char* servName;
    int servPort;
    char* string;
    char buffer [256+1];
    struct sockaddr_in servAddr;

    if(argc != 4)
    {
        printf("Error: three arguments are needed!");
        exit(1);
    }
    servName = argv[1];
    servPort = atoi(argv[2]);
    string = argv[3];
    memset(&servAddr,0,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    inet_pton(AF_INET, servName, &servAddr.sin_addr);
    servAddr.sin_port = htons(servPort);
    

    if((s = socket(PF_INET,SOCK_DGRAM, 0))<0)
    {
        perror("Error: socket failed!");
        exit(1);
    }
    printf(" string  = %s\n");
    sendto(s, string, strlen(string), 0, (struct sockaddr*)&servAddr,sizeof(servAddr));
    len = recvfrom(s, buffer, len, 0, NULL, NULL);
    buffer[len]= '\0';
    printf(" Echo string recieved: %s\n", buffer);
    close(s);
    exit(0);
}
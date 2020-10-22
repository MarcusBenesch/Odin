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

    if(argc != 3)
    {
        printf("Error: three arguments are needed!");
        exit(1);
    }
    servName = argv[0];
    servPort = atoi(argv[1]);
    string = argv[2];
    memset(&serveAddr,0,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sinport = htons(SERVER_PORT);
    serveAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if((s = socket(PF_INET,SOCK_DGRAM, 0))<0)
    {
        perror("Error: socket failed!");
        exit(1);
    }

    len = sendto(s, string, strlen(string), 0, (struct sockaddr)&servAddr,sizeof(servAddr));
    recvfrom(s, buffer, len, 0, NULL, NULL);
    buffer[len]= '\0';
    printf(" Echo string recieved: %s", buffer);
    close(s);
    exit(0);
}
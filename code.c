#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/*#include"csci4500utils.h"*/
int forkFunc( const char *str, char *args[])
{
    pid_t parent = getpid();
    pid_t pid = fork();
    //printf("test\n");

    if (pid == -1)
    {
        // error, failed to fork()
        //printf("Failed");
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        //printf("I am parent\n");
    }
    else
    {
        
        char *env_args[] = { (char *)0};
        execve(str, args, env_args);
        _exit(EXIT_FAILURE); // exec never returns
    }
}

int main(void)
{
    char *args[] = {"-a", "-l", "-a" (char *)0};
    forkFunc("/usr/bin/ls", args);
    printf("/////\n\n");
   args[0] = "";
   args[1] = (char *)0;
    forkFunc("/usr/bin/ls", args);
    return 0;
}
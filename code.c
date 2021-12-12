#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

 #include <sys/wait.h>
#include <sys/types.h>


int forkFunc()
{
    pid_t parent = getpid();
    pid_t pid = fork();
    printf("test\n");

    if (pid == -1)
    {
        // error, failed to fork()
        printf("Failed");
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        printf("I am parent\n");
        
    }
    else
    {
        // we are the child
        printf("I am child\n");
        execve("/usr/bin/ls", "-ls", environ);
        _exit(EXIT_FAILURE); // exec never returns
    }
}
int main(void)
{

    forkFunc();
    return 0;
}
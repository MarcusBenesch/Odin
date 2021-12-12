#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#include <sys/types.h>


int forkFunc()
{
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1)
    {
        // error, failed to fork()
        printf("Failed");
    }
    else if (pid > 0)
    {
        int status;
        printf("I am parent");
        waitpid(pid, &status, 0);
    }
    else
    {
        // we are the child
        printf("I am child");
        _exit(EXIT_FAILURE); // exec never returns
    }
}
int main(void)
{

    forkFunc();
    return 0;
}
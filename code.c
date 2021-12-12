#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


#include <sys/types.h>
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
        printf("I am parent\n");
    }
    else
    {
        
        char *env_args[] = { (char *)0};
        printf("child");
        execve(str, args, env_args);
        _exit(EXIT_FAILURE); // exec never returns
    }
}
int main(void)
{
    
    char *_args[] = { "-l", (char *)0};
    forkFunc("ls", _args);
    return 0;
}
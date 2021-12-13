/*
 * Auth: Marcus Benesch
 * Date: 12-12-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  Shell Programming Project
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/*#include"csci4500utils.h"*/
int forkFunc(const char *str, char *args[])
{
    /*pid_t parent = getpid();*/
    pid_t pid = fork();
    /*printf("test\n");*/

    if (pid == -1)
    {
        /* error, failed to fork()
        //printf("Failed");*/
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        /*printf("I am parent\n");*/
    }
    else
    {

        char *env_args[] = {(char *)0};
        execve(str, args, env_args);
        _exit(EXIT_FAILURE); 
    }
}

int findPath(char *path, const char *str, char *buf)
{

    char *tok;
    char *delim = ":";
    int count = 0;
    int x;
    char temp[1000];

    if (path != NULL)
    {
        x = access(str, X_OK);
        if (x == 0)
        {
            strcpy(buf, str);
            return 0;
        }
        else
        {
            for (tok = strtok(path, delim); tok != NULL; tok = strtok(NULL, delim))
            {

                strcpy(temp, tok);
                strcat(temp, "/");
                strcat(temp, str);
                x = access(temp, X_OK);
                
                if (x == 0)
                {
                    
                    strcpy(buf, temp);
                    return 0;
                }
                count++;
            }
        }
    }
    return 1;
}
int writestring(int fd, const char *str)
{

    /* Maximum number of loop iterations in case things go bad. */
    const size_t MAXSTRLEN = 256;

    int count = 0;
    int i;
    int tmp = 0;
    
    for (i = 0; i < MAXSTRLEN; i++)
    {

        char c = str[i];

        if (c != '\0')
        {
            tmp = write(fd, &c, 1);
        }
        else
        {

            
            return count + 1;
        }
        if (tmp == -1)
        {
            return -1;
        }
        count = count + 1;
    }

    return count;
}

int writeline(int fd, const char *str)
{

    /* Maximum number of loop iterations in case things go bad. */
    const size_t MAXSTRLEN = 256;

    int count = 0;
    int i;
    int tmp = 0;
    char end = '\n';
    for (i = 0; i < MAXSTRLEN; i++)
    {

        char c = str[i];

        if (c != '\0')
        {
            tmp = write(fd, &c, 1);
        }
        else
        {

            tmp = write(fd, &end, 1);
            return count + 1;
        }
        if (tmp == -1)
        {
            return -1;
        }
        count = count + 1;
    }

    return count;
}

int readline(int fd, char *buf, int bufsz)
{
    /* Maximum number of loop iterations in case things go bad. */
    char temp[256];
    int count = 0;
    int err = 1;
    int i;
    for (i = 0; i < 255; i++)
    {
        err = read(fd, &temp[i], 1);
        if (i == bufsz - 1)
        {
            count = i;
            break;
        }
        if (temp[i] == '\n' || temp[i] == '\0')
        {
            count = i;
            break;
        }
        if (err == -1 || err == 0)
        {
            count = i;
            break;
        }
    }

    for (i = 0; i < count; i++)
    {
        buf[i] = temp[i];
    }
    buf[count] = '\0';

    if (err < 1)
    {
        return err;
    }

    return count;
}

/***********************************************************************************************************/

int main(void)
{

    char input[256];
    char tempString[256];
    char *path = getenv("PATH");

    char tp[1000];

    printf("%s", path);

    while (1)
    {

        sprintf(tempString, ">> ");

        writestring(1, tempString);

        int bytes_read;
        bytes_read = readline(0, &input[0], 256);

        if (bytes_read > 0)
        {

            sprintf(tempString, "readline(): Got: \"%s\" (rval = %d)\n\n", input, bytes_read);
            /*writestring( 1, tempString);*/
            char *delims = ";";
            char *tokens[10];
            int i;
            char *token;
            char jobs[10][256];
            char ops[10][10];
            for (i = 0, token = strtok(input, delims); token != NULL && i < 10;
                 token = strtok(NULL, delims), i++)
            {

                tokens[i] = token;
                strcpy(jobs[i], tokens[i]);
                if (strchr(token, '&') && strchr(token, '|'))
                {
                    strcpy(ops[i], "1 2");
                }
                else if (strchr(token, '&'))
                {
                    strcpy(ops[i], "1");
                }
                else if (strchr(token, '|'))
                {
                    strcpy(ops[i], "2");
                }
                else
                {
                    strcpy(ops[i], "");
                }
            }
            /*tokens[i] = jobs*/
            delims = "&&||";
            char *commands[10][10];
            char *command;
            int j;
            int k;

            int count[i + 1];
            char simCom[10][10][256];
            /*printf("jobs\n");*/
            for (k = 0; k < i; k++)
            {
                count[k] = 0;
                for (j = 0, command = strtok(tokens[k], delims); command != NULL && j < 10;
                     command = strtok(NULL, delims), j++)
                {
                    count[k] = j;
                    commands[k][j] = command;
                    /*printf("%s\n", commands[k][j]);*/
                    strcpy(simCom[k][j], commands[k][j]);
                }
            }
            delims = " ";
            /*char *sma[10][10][10];*/
            char *sm;
            int c1;
            int c2;
            int temp = 0;
            int c3;
            char *cmd;
            int argCount = 1;
            char *argsOfSM[10];
            argsOfSM[0] = "a";
            char path2[90];
            char *tp;
            strcpy(tp, path);

            /*printf("debug\n");*/

            /*printf("args\n");*/

            for (c1 = 0; c1 < i; c1++)
            {

                
                sprintf(tempString, "Job #%d: \"%s\"\n", c1, jobs[c1]);
                /*writestring( 1, tempString);*/
                sprintf(tempString, "   seqops[] = [ %s ]\n", ops[c1]);
                /*writestring( 1, tempString);*/
                for (c2 = 0; c2 <= count[temp]; c2++)
                {
                    /*simple commands*/
                    sprintf(tempString, "   Simple Command #%d = \"%s\"\n", c2, simCom[c1][c2]);
                    /*writestring( 1, tempString);*/
                    for (c3 = 0, sm = strtok(commands[c1][c2], delims); sm != NULL && c3 < 10;
                         sm = strtok(NULL, delims), c3++)
                    {

                        /*arguments*/
                        if (c3 == 0)
                        {
                            cmd = sm;
                            /*sprintf(tempString, "      cmd = \"%s\"\n", sm);
                            writestring( 1, tempString);*/
                        }
                        else
                        {
                            argsOfSM[argCount] = sm;
                            argCount++;
                            sprintf(tempString, "      arg[%d] = \"%s\"\n", c3 - 1, sm);
                            /*writestring( 1, tempString);*/
                        }
                        /*ma[c1][c2][c3] = sm;
                        printf("%s\n", sma[c1][c2][c3]);*/
                    }
                    if (c3 == 1)
                    {
                        sprintf(tempString, "      args = (None supplied)");
                        /*writestring( 1, tempString);*/
                    }
                    char path1[90];
                    /*printf("debug1\n");
                    printf("Sim Com 1 = %s\n", cmd);
                    printf("path1 = %s", path1);*/
                    int bool = findPath(tp, cmd, path1);
                    printf("debug");
                    strcpy(tp, path);
                    /*printf("path = %s\n", path1);*/
                    if (bool == 0)
                    {
                        argsOfSM[argCount] = (char *)0;
                        forkFunc(path1, argsOfSM);

                        
                        /*printf("string = %s", path1);*/
                    }
                    else
                    {
                        sprintf(tempString, "Command: %s not found", cmd);
                        writestring(1, tempString);
                    }
                    argCount = 1;

                    /*printf("\n///////////////////////////////////////////////////\n");
                    sprintf(tempString, "\n\n");
                    writestring( 1, tempString);*/
                }
                temp++;
            }
        }
        else
        {
            sprintf(tempString, "readline(): Returned with code = %d\n", bytes_read);
            writestring(1, tempString);
        }
    }

    return (EXIT_SUCCESS);
}
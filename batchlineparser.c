/*
 * Auth: Marcus Benesch
 * Date: 11-19-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  PREPROJECT-05, A batchline parser program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*#include"csci4500utils.h"*/

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


    while (1)
    {

        printf(">> ");

        int bytes_read;
        bytes_read = readline(0, &input[0], 256);

        if (bytes_read > 0)
        {

            printf("readline(): Got: \"%s\" (rval = %d)\n\n", input, bytes_read);
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
                if(strchr(token,'&')&&strchr(token,'|'))
                {
                    strcpy(ops[i], "1 2");
                }
                else if(strchr(token,'&'))
                {
                    strcpy(ops[i], "1");
                }
                else if(strchr(token,'|'))
                {
                    strcpy(ops[i], "2");
                }
                else{
                    strcpy(ops[i], "");
                }
            }
            ///tokens[i] = jobs
            delims = "&&||";
            char *commands[10][10];
            char *command;
            int j;
            int k;
            
            int count[i+1];
            char simCom[10][10][256];
            //printf("jobs\n");
            for (k = 0; k < i; k++)
            {
                count[k] = 0;
                for (j = 0, command = strtok(tokens[k], delims); command != NULL && j < 10;
                     command = strtok(NULL, delims), j++)
                {
                    count[k] = j;
                    commands[k][j] = command;
                    //printf("%s\n", commands[k][j]);
                    strcpy(simCom[k][j], commands[k][j]);
                }
            }
            delims = " ";
            //char *sma[10][10][10];
            char *sm;
            int c1;
            int c2;
            int temp = 0;
            int c3;
            //printf("debug\n");
            
            //printf("args\n");

            for (c1 = 0; c1 < i; c1++)
            {
                printf("Job #%d: \"%s\"\n", c1, jobs[c1]);
                printf("   seqops[] = [ %s ]\n", ops[c1]);
                for (c2 = 0; c2 <= count[temp]; c2++)
                {
                    
                    printf("   Simple Command #%d = \"%s\"\n", c2, simCom[c1][c2]);
                    for (c3 = 0, sm = strtok(commands[c1][c2], delims); sm != NULL && c3 < 10;
                         sm = strtok(NULL, delims), c3++)
                    {
                        if(c3 ==0)
                        {
                        printf("      cmd = \"%s\"\n", sm);
                        }
                        else{
                            printf("      arg[%d] = \"%s\"\n", c3-1, sm);
                        }
                        //sma[c1][c2][c3] = sm;
                        //printf("%s\n", sma[c1][c2][c3]);
                    }
                    if(c3 ==1)
                    {
                        printf("      args = (None supplied)");
                    }
                    printf("\n\n");
                }
                temp++;
                
            }
            
                
            
            
        }
        else
        {
            printf("readline(): Returned with code = %d\n", bytes_read);
        }
    }

    return (EXIT_SUCCESS);
}
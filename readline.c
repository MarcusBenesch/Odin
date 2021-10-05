/*
 * Auth: Marcus Benesch
 * Date: 09-19-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  PREPROJECT-02, Funtion to read a line
 */

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int readline( int fd, char *buf, int bufsz )
{
    /* Maximum number of loop iterations in case things go bad. */
    char *temp[256];
    int count = 0;
    int err = 1;
    int i;
    for (i = 0; i < 255; i++) {
        err = read(fd, *temp, 1);
        if(i == bufsz -1)
        {
            count = i;
            break;

        }
        if(*temp[i] == '\n' || *temp[i] == '\0')
        {
            count = i;
            break;
        }
        if(err == -1 || err == 0)
        {
            count = i;
            break;
        }
        


    }
    for (i = 0; i < count; i++) {
        *buf[i] = *temp[i];

    }
    buf[count]='\0';

    if(err<1)
    {
    return err;
    }

    return count;


}
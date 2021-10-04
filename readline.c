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
    char *temp[bufsz];
    count = 0;
    err = 1;
    int i;
    for (i = 0; i < bufsz-1; i++) {
        tmp = read(fd, *str, 1);
        if(temp[i] == '\n' || temp[i] == '\0')
        {
            count = i;
            break;
        }
        if(tmp == -1 || tmp == 0)
        {
            count = i;
            err = tmp;
            break;
        }
        


    }
    for (i = 0; i < count; i++) {
        buf[i] = temp[i];

    }
    buff[count]='\0';

    if(err<1)
    {
    return err;
    }

    return count;


}
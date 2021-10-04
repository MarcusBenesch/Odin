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
    
    int count = 0;
    int i;
    int tmp = 0;
    int end = '\0';
    for (i = 0; i < bufsz-1; i++) {
        tmp = read(int fd, *buf, 1);
        if(tmp == -1 || tmp == 0){
            return tmp;
        }
        
        }
        if(buf[i]== '\0' || buf[i]== '\n')
        {
            return i + 1;
        }


    }
    return bufsz + 1;


}
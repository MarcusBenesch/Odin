/*
 * Auth: Marcus Benesch
 * Date: 09-19-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  PREPROJECT-01, A Simple "Hello, World" C program.
 */

#include<stdio.h>
#include<stdlib.h>


int writeline( int fd, const char *str ) {
  
  /* Maximum number of loop iterations in case things go bad. */
  const size_t MAXSTRLEN = 256;

    int count = 0;
    for (int i = 0; i < MAXSTRLEN; i++) {

        char c = str[i]; 

        if(c = '\0')
        {
            int write(fd, c, 1);
        }
        if(write == -1)
        {
            return -1;
        }

    }

  



} /* end writeline() */
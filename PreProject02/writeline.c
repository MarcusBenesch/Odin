/*
 * Auth: Marcus Benesch
 * Date: 09-19-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  PREPROJECT-02, Funtion to write a string to a line.
 */

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>


int writeline( int fd, const char *str ) {
  
  /* Maximum number of loop iterations in case things go bad. */
  const size_t MAXSTRLEN = 256;

    int count = 0;
    int i;
    int tmp = 0;
    char end = '\n';
    for (i = 0; i < MAXSTRLEN; i++) {

        char c = str[i]; 

        if(c != '\0')
        {
            tmp = write(fd,&c, 1);
        }
        else{

            tmp = write(fd,&end, 1);
            return count + 1;
        }
        if(tmp == -1)
        {
            return -1;
        }
        count = count + 1;
        

    }

  

return count;

} /* end writeline() */
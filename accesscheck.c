/*
 * Auth: Marcus Benesch
 * Date: 10-12-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  PREPROJECT-03, Checking the access parameters of a file.
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main( int argc, char *argv[] ) {


if( argc != 2 ) {
      printf("ERROR: Usage: accesscheck <pathname>\n");
   }

else{
    int f;
    int r;
    int w;
    int x;
    printf("Checking: \"%s\" ...\n", argv[1]);
    f = access( argv[1], F_OK);
    printf("F_OK = %d\n", f);
    if(f != 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }
    r = access( argv[1], R_OK);
    printf("R_OK = %d\n", r);
    if(f != 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }
    w = access( argv[1], W_OK);
    printf("W_OK = %d\n", w);
    if(f != 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }
    x = access( argv[1], X_OK);
    printf("X_OK = %d\n", x);
    if(f != 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }
}
return 1;

}
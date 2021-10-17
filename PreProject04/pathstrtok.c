/*
 * Auth: Marcus Benesch
 * Date: 10-17-2021
 * Course: CSCI-4500 (Sec: 002)
 * Desc:  PREPROJECT-04, List out environment variables.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main( int argc, char *argv[] ) {

    char *path = NULL;
    char *tok;         
    char *delim = ":";
    int count = 0;

    path = getenv( "PATH" );
    printf("Checking \"PATH\"...\n");
    if( path != NULL ) {
        printf("PATH = \"%s\"\n", path);
       
        for( tok = strtok( path, delim ); tok != NULL;  tok = strtok( NULL, delim ) ) {
            printf("path[%d] = \"%s\"\n",count, tok);
            count ++;
        }
    }
    return 0;
}
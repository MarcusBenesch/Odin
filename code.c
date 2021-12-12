#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/*#include"csci4500utils.h"*/
int findPath(const char *path,const char *str, char *buf)
{
char *path = NULL;
    char *tok;         
    char *delim = ":";
    int count = 0;
    int x;

    

    if( path != NULL ) {   
        x = access( str, X_OK); 
        char temp[1000];
        if(x == 0)
        {
            strcpy(buf, str);
                return 0;
        } 
        else{
        for( tok = strtok( path, delim ); tok != NULL;  tok = strtok( NULL, delim ) ) {

            
            strcpy(temp, tok);
            strcat(temp, "/");
            strcat(temp, str);
            printf("s = %s\n", temp );
            x = access( temp, X_OK); 
            printf("x = %d\n", x);
            if(x == 0)
            {   
                
                strcpy(buf, temp);
                //return 0;
            }        
            count ++;
        }
        }
    }
    return 1;
}

int main(void)
{
    char path1[90];
    char *path = getenv( "PATH" );
    int bool = findPath(path, "ls", path1);
    path = getenv( "PATH" );
    printf("//////////////////////////////");
    int bool2 = findPath(path,"ls", path1);

    printf("first = %d, second = %d\n", bool, bool2);
}
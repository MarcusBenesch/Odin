#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/*#include"csci4500utils.h"*/
int findPath(const char *str, char *buf)
{
char *path = NULL;
    char *tok;         
    char *delim = ":";
    int count = 0;
    int x;

    path = getenv( "PATH" );

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
            x = access( temp, X_OK); 
            printf("temp\n");
            if(x == 0)
            {
                printf("\ntemp\n");
                strcpy(buf, temp);
                return 0;
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
    
    int bool = findPath("cd", path1);
    int bool2 = findPath("ls", path1);

    printf("first = %d, second = %d\n", bool, bool2);
}
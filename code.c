#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
/*#include"csci4500utils.h"*/
int findPath(char *path,const char *str, char *buf)
{

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
            printf("path = %s\n", path);
        for( tok = strtok( path, delim ); tok != NULL;  tok = strtok( NULL, delim ) ) {

            
            strcpy(temp, tok);
            strcat(temp, "/");
            strcat(temp, str);
            x = access( temp, X_OK); 
            printf("%s\n", temp);
            if(x == 0)
            {
                printf("\n%s\n", temp);
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

char *path = NULL;
char * tp;
path = getenv( "PATH" );
strcpy(tp,path)
    char path1[90];
    
    int bool = findPath(tp,"echo", path1);
    strcpy(tp,path)
    int bool2 = findPath(tp,"ls", path1);

    printf("first = %d, second = %d\n", bool, bool2);
}
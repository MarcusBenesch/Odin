#include <stdio.h>
#include <stdlib.h>

#include <string.h>


#include <sys/types.h>
int findPath(const char *str, char *buf)
{
char *path = NULL;
    char *tok;         
    char *delim = ":";
    int count = 0;
    int x =1;

    path = getenv( "PATH" );

    if( path != NULL ) {   
        //x = access( str, X_OK); 
        char temp[90];
        if(x == 0)
        {
            strcpy(buf, str);
                return 0;
        } 
        else{
        for( tok = strtok( path, delim ); tok != NULL;  tok = strtok( NULL, delim ) ) {

            
            strcpy(temp, tok);
            strcat(temp, "\\");
            strcat(temp, str);
            printf("%s\n", temp);
            //x = access( temp, X_OK); 
            if(x == 0)
            {
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

    findPath("ls", &path1[0]);
    printf("%s", path1);
    return 0;
}
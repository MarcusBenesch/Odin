#include <stdio.h>
#include <ctype.h>
#include <string.h> 

static char *dial[] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate();
int checkword();

int main( int ac, char *av[] )
{   
    printf("%d  ", checkword("WRITING\n"));
    

}
//This function takes in 7 numbers, which are the 7 digits of the phone number and generates all possible words.
void generate( int num[7])
{
    //char array of the output
    char output[8];
    output[8] ='\n';
    //Debugging Puposes
    //printf("number [0] = %d, Sting = %s String Length = %d\n",num[0], dial[num[0]], strlen(dial[num[0]]));
    //printf("number [1] = %d, Sting = %s String Length = %d\n",num[1], dial[num[1]], strlen(dial[num[1]]));
    //Iterate through the first digit possibilities
    for(int a =0; a < strlen(dial[num[0]]); a++)
    {
        
        output [0] = dial[num[0]][a];
        //Iterate through the second digit possiblilties
        for(int b =0; b < strlen(dial[num[1]]); b++)
        {
            
            output [1] = dial[num[1]][b];
            //Iterate through the third digit possiblilties
            for(int c =0; c < strlen(dial[num[2]]); c++)
            {
                
            output [2] = dial[num[2]][c];
            //Iterate through the fourth digit possibilities
                for(int d =0; d < strlen(dial[num[3]]); d++)
                {
                    
                    output [3] = dial[num[3]][d];
                    //Iterate through the fifth digit possibilities
                    for(int e =0; e < strlen(dial[num[4]]); e++)
                    {
                        
                        output [4] = dial[num[4]][e];
                        //Iterate through the sixth digit possibilities
                        for(int f =0; f < strlen(dial[num[5]]); f++)
                        {
                            output [5] = dial[num[5]][f];
                            //Iterate through the seventh digit possibilities
                            for(int g =0; g < strlen(dial[num[6]]); g++)
                            {
                                output [6] = dial[num[6]][g];
                                //Debug purposes
                                //printf("%s", output);
                                if(checkword(output) == 1)
                                {
                                printf("%s", output);
                                }
                            }
                        }
                    }
                }
            }
        }

    }

}
//This function checks to see if the word is in the file P4WORDS.TXT via binary search
//P4WORDS.TXT must be in the current directory and alphabetical with all words being 8 bytes.
int checkword(char input[8])
    {
        int infinite = 0;
        FILE *words;
        words = fopen("./P4WORDS.TXT", "r" );
        if (words == NULL) 
        { 
            printf("File Not Found!\n"); 
            return -1; 
        } 

        fseek(words, 0L, SEEK_END);  
        long int length = ftell(words); 
        //Debugging Purposes
        //printf("The file is length %d", length);
        int l = 0; 
        int r = length/8;
        int mid = (l + r)/2;
        char buffer [8];
        //Debug purposes
         //printf("buffer = %s, input = %s, l = %d, r = %d, mid = %d\n", buffer, input, l, r, mid);
        while(l != r)
        {
            fseek(words, (mid*8), SEEK_SET);
            fgets(buffer, 8, words);
            for(int x =0; x<8; x++)
            {
                buffer[x] = toupper(buffer[x]);
            }
            buffer[8] = '\n';
            //Debugging information
            printf("buffer = %s, input = %s, l = %d, r = %d, mid = %d\n", buffer, input, l, r, mid);
            if(strcmp(buffer, input) < 0)
            {
                l = mid;
                mid = (l + r)/2;
            }
            if(strcmp(buffer, input) > 0)
            {
                r = mid;
                mid = (l + r)/2;
            }
            if(strcmp(buffer, input) == 0)
            {
                
                printf("%s", buffer);
                fclose(words);
                return 1;
            }
            if(l -r == 1|| l - r == -1)
            {
                printf("strcmp = %d", strcmp(buffer, input) );
                infinite = infinite+1;

            }
            if(infinite == 2)
            {
                break;
            }



        }

        fclose(words);
        return 0;
    }
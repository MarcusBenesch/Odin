#include <stdio.h>
#include <ctype.h>
#include <string.h> 

static char *dial[] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate();
int checkword();

int main( int ac, char *av[] )
{   
    char temp[12];
    int phoneNum[7];
    
    printf("Enter a phone number: ");
    while( (fgets(temp,13,stdin)) != NULL)
    {
        
        //validate input char by char
        if(!isdigit(temp[0])||!isdigit(temp[1])||!isdigit(temp[2])||!isdigit(temp[4])||!isdigit(temp[5])||!isdigit(temp[6])||!isdigit(temp[8])||!isdigit(temp[9])||!isdigit(temp[10])||!isdigit(temp[11])|| temp[3] != '-'|| temp[7]!= '-')
        {
            printf("%s\n", temp);
            printf("Invalid number, try again. The phone number should be 10 digits separated by dashes. ");
        }
        else
        {
            printf("xxx %s\n", temp);
            phoneNum[0] = temp[4] -48;
            phoneNum[1] = temp[5] -48;
            phoneNum[2] = temp[6] -48;
            phoneNum[3] = temp[8] -48;
            phoneNum[4] = temp[9] -48;
            phoneNum[5] = temp[10] -48;
            phoneNum[6] = temp[11] -48;
            printf("%d%d%d-%d%d%d%d", phoneNum[0],  phoneNum[1],  phoneNum[2],  phoneNum[3],  phoneNum[4],  phoneNum[5],  phoneNum[6]); 
            generate(phoneNum);
            
        }
        
        
    }
    

}
//This function takes in 7 numbers, which are the 7 digits of the phone number and generates all possible words.
void generate( int num[7])
{
    //char array of the output
    char output[8];
    output[7] ='\n';
    output [3] = '\n';
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
                                if(checkword(output))
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
        int ans = 0;
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
         printf("buffer = %s, input = %s, l = %d, r = %d, mid = %d\n", buffer, input, l, r, mid);
        while(l != r)
        {
            fseek(words, (mid*8), SEEK_SET);
            fgets(buffer, 8, words);
            for(int x =0; x<8; x++)
            {
                buffer[x] = toupper(buffer[x]);
            }
            //Debugging information
            //printf("buffer = %s, input = %s, l = %d, r = %d, mid = %d\n", buffer, input, l, r, mid);
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

                ans == 1;
                break;
            }
            if(l -r == 1|| l - r == -1)
            {
                infinite = infinite+1;

            }
            if(infinite == 2)
            {
                break;
            }



        }

        fclose(words);
        return ans;
    }
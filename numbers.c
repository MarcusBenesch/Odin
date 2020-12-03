#include <stdio.h>
#include <string.h> 

static char *dial[] = { "XXX\n", "XXX\n", "ABC\n", "DEF\n", "GHI\n", "JKL\n", "MNO\n", "PQRS\n", "TUV\n", "WXYZ\n"};

void generate();
int phoneNum[7];
char word [8];

int main( int ac, char *av[] )
{
    int numbers[7] = {2,4,9,3,4,7,9};
    generate(numbers);
}
//This function takes in 7 numbers, which are the 7 digits of the phone number and generates all possible words.
void generate( int num[7])
{
    //char array of the output
    char output[8];
    output[7] ='\n';
    output [3] = '\n';
    //Debugging Puposes
    printf("number [0] = %d, Sting = %s",num[0], dial[num[0]]);

    //Iterate through the first digit possibilities
    for(int a =0; a < strlen(dial[num[0]]); a++)
    {
        //Debugging Puposes
        
        
        output [0] = dial[num[0]][a];
        printf("%c", output[0]);

    }
}


/**
//Iterate through the fourth digit possibilities
                for(int d =0; a < strlen(dial[num[3]]); d++)
                {
                    output [3] = dial[num[3]][d];
                    //Iterate through the fifth digit possibilities
                    for(int e =0; a < strlen(dial[num[4]]); e++)
                    {
                        output [4] = dial[num[4]][e];
                        //Iterate through the sixth digit possibilities
                        for(int f =0; a < strlen(dial[num[5]]); f++)
                        {
                            output [5] = dial[num[5]][f];
                            //Iterate through the seventh digit possibilities
                            for(int g =0; a < strlen(dial[num[6]]); g++)
                            {
                                output [6] = dial[num[6]][g];
                                printf("String possibility is %s\n", output);
                            }
                        }
                    }
                }
                    **/
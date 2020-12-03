#include <stdio.h>
#include <errno.h>
#include <ctype.h> 
#include <string.h> 

static char *dial[] = { "XXX", "XXX", "ABC\n", "DEF\n", "GHI\n", "JKL\n", "MNO", "PQRS", "TUV", "WXYZ"};

void generate();
int phoneNum[7];
char word [8];

int main( int ac, char *av[] )
{
    char temp[7] = {'1', '2', '3', '4', '5', '6', '7'};
    generate(temp);
}
//This function takes in 7 numbers, which are the 7 digits of the phone number and generates all possible words.
void generate( char num[7])
{
    printf("Test\n");
    char *three, *four, *five, *six, *seven, *eight, *nine;
    for(three = dial[num['3'] -'0']; *three; three++ )
    {
        printf("%c", three);
    }
}
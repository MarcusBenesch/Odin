#include <stdio.h>
#include <string.h> 

static char *dial[] = { "XXX\n", "XXX\n", "ABC\n", "DEF\n", "GHI\n", "JKL\n", "MNO\n", "PQRS\n", "TUV\n", "WXYZ\n"};

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
    for(int a =0; a < strlen(dial[3]); a++)
    {
        printf("%c", a);
    }
}
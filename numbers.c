#include <stdio.h>
#include <string.h> 

static char *dial[] = { "XXX\n", "XXX\n", "ABC\n", "DEF\n", "GHI\n", "JKL\n", "MNO\n", "PQRS\n", "TUV\n", "WXYZ\n"};

void generate();
int phoneNum[7];
char word [8];

int main( int ac, char *av[] )
{
    int numbers[7] = {2,4,0,1,1,7,9};
    generate(numbers);
}
//This function takes in 7 numbers, which are the 7 digits of the phone number and generates all possible words.
void generate( int num[7])
{
    printf("number [0] = %d, Sting = %s",num[0], dial[num[0]]);
    for(int a =0; a < strlen(dial[num[0]]); a++)
    {
        printf("%c", dial[num[0]][a]);
    }
}
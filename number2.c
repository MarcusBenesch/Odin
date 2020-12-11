#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h> 
#define SIZE 8

static char *dial[] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

struct tree_node {
struct tree_node *left, *right;
char word[ SIZE ];
};
typedef struct tree_node node;


int generate();
int checkword();
void insertNode();
void insert();
void debug();

int main( int ac, char *av[] )
{   
    
    node *root = NULL;
    insertNode(*root);
    int temp [] = {5,5,5,5,5,5,5};
    //generate(temp, root);
    debug(root);
    
}
//This function takes in 7 numbers, which are the 7 digits of the phone number and generates all possible words.
int generate( int num[7],  node * root)
{
    
    //char array of the output
    char output[8];
    output[7] = '\0';
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
                                //printf("|%s|\n", output);
                                if(checkword(&root, output) == 1)
                                {
                                printf("%s\n", output);
                                }
                            }
                        } 
                    }
                }
            }
        }

    }
    return 0;

}

void insertNode(node ** root)
{
    FILE *words;
        words = fopen("./P4WORDS.TXT", "r" );
        if (words == NULL) 
        { 
            printf("File Not Found!\n"); 
            return; 
        } 

        fseek(words, 0L, SEEK_END);  
        long int length = ftell(words); 
        char buffer [8];
        printf("Length = %d\n", length);
        for(int count = 0; count < length-7; count = count + 8)
        {
            fseek(words, count, SEEK_SET);
            fgets(buffer, 8, words);
            for(int x =0; x<8; x++)
            {
                buffer[x] = toupper(buffer[x]);
            }
            insert(&root, buffer);
            printf("Buffer = %s\n", buffer);

        }
        fclose(words);

        //debug(root);
}

void insert(node ** tree, char data [8])
{
    //printf("Inserting %s into %d\n", data, tree);
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = NULL;
        temp->right = NULL;
        strcpy(temp->word, data);
        *tree = temp;
        return;
    }

    if(strcmp((*tree)->word, data)>0)
    {
        insert(&(*tree)->left, data);
    }
    else if(strcmp((*tree)->word, data)<0)
    {
        insert(&(*tree)->right, data);
    }

}


int checkword( node **root, char word[] )
{
    //Debugging purposes
    //printf("Checkword reached\n");
    while ( *root != NULL )
    {
        //root gets assigned the link that goes to the left
        if ( strcmp((*root)->word, word)>0)
        {
            root = &(*root)->left;
        }
        //root gets assigned the link that goes right    
        else if (strcmp((*root)->word, word)<0)
        {
            root = &(*root)->right;
        }
        else
        {
        return(1);
        }
    }
    return(0); // fell off the end of the while loop
}



void debug(node * tree)
{
    if (tree)
    {
        debug(tree->left);
        printf("%s\n",tree->word);
        debug(tree->right);
    }
}
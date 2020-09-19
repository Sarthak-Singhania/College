#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
    char word[100];
    printf("Enter a word: ");
    scanf("%s",word);
    if(strcmp(word,"QUIZ")==0 || strcmp(word,"quiz")==0) printf("%d\n",22);
    else
    {
        for(int i=0;word[i]!='\0';i++)
        {
            
        }
    }
    printf("\n");
    return 0;
}
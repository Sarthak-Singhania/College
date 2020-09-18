#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char word[100];
    printf("Enter a word: ");
    scanf("%s",word);
    if(word=="QUIZ" || word=="quiz") printf("22");
    else
    {
        char a=word[0];
        printf("%s",a);
    }
}
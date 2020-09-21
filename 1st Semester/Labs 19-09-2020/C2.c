#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(void)
{
    int i,shift,j=0;
    char message[100],ch;
	printf("Enter a message to decrypt: ");
	fgets(message,100,stdin);
	printf("Enter shift: ");
	scanf("%d", &shift);
    for(j=0;message[j]!='\0';j++)
    {
        message[j]=toupper(message[j]);
    }
    if(shift>26)
    {
        printf("INVALID SHIFT VALUE");
        exit(0);
    }
    for(i=0;i<message[i]!='\0';i++)
    {
        if(message[i]==' ')
        {
        continue;
        }
        if(message[i]-shift<65) message[i]=message[i]+26;
        message[i]-=shift;
    }
    for(i=0;i<message[i]!='\0';i++)
    {
        if(message[i]==' ')
        {
            continue;
        }
        if(message[i]=='Q'&&message[i+1]=='Q')
        {    
            printf(" ");
            i+=2;
        }

        printf("%c",message[i]);
    }
    return 0;
}
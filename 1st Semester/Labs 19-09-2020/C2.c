#include<stdio.h> 
int main()
{
	char message[100], ch;
	int shift;
	printf("Enter a message to decrypt: ");
	fgets(message,100,stdin);
	printf("Enter shift: ");
	scanf("%d", &shift);
	for(int i=0; message[i]!='\0'; i++)
    {
        ch=message[i];
        if(ch!=' ' && )
        {
            ch-=shift;
            if(ch<'A')
            {
                ch=ch+'Z'-'A'+1;
            }
            message[i]=ch;
        }
	}
	printf("Decrypted message: %s\n", message);
	return 0;
}
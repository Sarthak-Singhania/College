#include <stdio.h> 
#include <string.h>
char isPalRec(char str[],int s, int e) 
{
	if (str[s]!=' ' && str[s]!=',')
	{
		if (s==e) return 1;
		if (tolower(str[s])!=tolower(str[e])) return 0;
		if (s < e + 1) return isPalRec(str, s + 1, e - 1); 
		return 1; 
	}
}
int main() 
{ 
	char str[500];
	printf("Enter sentence to check for pallindrome: ");
	scanf("%[^\n]s",str);
	int n=strlen(str);
	if (isPalRec(str, 0, n - 1))  printf("Yes\n"); 
	else printf("No\n"); 
	return 0; 
} 

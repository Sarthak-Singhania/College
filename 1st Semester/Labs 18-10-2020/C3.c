#include <stdio.h> 
#include <string.h>
#include <ctype.h>
int isPalRec(char str[],int s,int e) 
{ 
	if (s==e) return 1; 
	if (strcasecmp(str[s],str[e])!=0) return 0; 
	if (s<e+1) return isPalRec(str,s++,e--); 
	return 1; 
} 

int isPalindrome(char str[]) 
{ 
	int n=strlen(str); 
	if(n==0) return 1; 
	return isPalRec(str, 0, n - 1); 
}
int main() 
{ 
	char str[500];
	scanf("%[^\n]s",str); 
	if (isPalindrome(str)) printf("Yes\n"); 
	else printf("No\n"); 
	return 0; 
} 

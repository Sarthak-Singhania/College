#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main() 
{ 
	FILE *file;
	char a[600],ch;
	int cnt=0;
	file=fopen("test1.txt","r");
	while ((ch=fgetc(file))!=EOF)
	{
		cnt+=1;
		a[cnt]=ch;
		printf("%s",a);	
	}
} 

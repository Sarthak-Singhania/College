#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int count()
{
	FILE *file;
	char c;
	file=fopen("test1.txt","r");
	int cnt=0;
	while(1>0)
	{
		c=fgetc(file);
		if(c!=EOF) cnt+=1;
		else break;
	}
	return cnt;
}

int main() 
{ 
	FILE *file;
	char c;
	char arr[1000];
	int p;
	file=fopen("test1.txt","r");
	int nchar;
	nchar=count();
	for(int i=0;i<nchar;i++) arr[i]=fgetc(file);
	fclose(file);
	p=nchar-1;
	int count=0;
	int j;
	int k=0;
	FILE *file;
	file=fopen("revtest2.txt","w");
	for(int i=nchar-2;i>=0;i--)
	{
		if(arr[i]==' '||arr[i]=='\n')
		{
			for(j=i;j<p;j=j+1)
			{
				if (count==0) j=j+1;
				count++;
				if(k==0)
				{
					if(arr[j]=='\n')
					{
						filerintf(file," ");
						printf(" ");
						k++;
					}
					else
					{
						filerintf(file,"%c",arr[j]);
							printf("%c",arr[j]);
					}
				}
				else
				{
					if (arr[j]!=' ')
					{
						filerintf(file,"%c",arr[j]);
						printf("%c",arr[j]);
					}
					else
					{
						filerintf(file,"\n");
						printf("\n");
						k=0;
					}
				}
			}

			p=i;
		}
	}
	filerintf(file," ");
	printf(" ");
	for(int i=0;i<100;i++)
	{
		filerintf(file,"%c",arr[i]);
		printf("%c",arr[i]);
		if(arr[i]==' ') break;
	}
	fclose(file);
	printf("\n");
} 

#include <stdio.h> 
#include <string.h>

char reVal(int num) 
{ 
	if (num>=0 && num<=9) return (char)(num+'0');
	else return (char)(num-10+'A');
} 

void strev(char *str) 
{ 
	int len=strlen(str);
	int i;
	for (i=0;i<len/2;i++) 
	{ 
		char temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	} 
} 

int val(char c) 
{ 
	if (c>='0' && c<='9') return (int)c-'0';
	else return (int)c-'A'+10;
}

int toDeci(char *str, int base) 
{ 
	int len=strlen(str);
	int power=1;
	int num=0; 
	int i;
	for (i=len-1;i>=0;i--) 
	{ 
		if (val(str[i])>=base) 
		{ 
    		printf("Invalid Number");
	    	return -1;
		} 
		num+=val(str[i])*power;
		power=power*base;
	} 
	return num;
} 

char* fromDeci(char res[],int base,int inputNum) 
{ 
	int index=0;
	while (inputNum>0) 
	{ 
		res[index++]=reVal(inputNum%base);
		inputNum/=base;
	} 
	res[index]='\0';
	strev(res);
	return res;
} 

int main() 
{ 
	char res[100],str[100];
	int inputNum,base1,base2;
    printf("Inputs: ");
    scanf("%s",str);
	scanf("%d",&base1);
	scanf("%d",&base2);
	inputNum=toDeci(str,base1);
	printf("\nConverted number: %s\n",fromDeci(res,base2,inputNum));
	return 0;
}

#include <stdio.h>
void reverse(char *str) 
{ 
    if (*str) 
    { 
	    reverse(str+1); 
	    printf("%c", *str); 
    }
}
int main() 
{ 
    char a[500];
    printf("Input string to be reversed: ");
    scanf("%[^\n]s",a); 
    reverse(a);
    printf("\n"); 
    return 0; 
} 

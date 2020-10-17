#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int power(int m,int n,int cnt[])
{ 
    if(n==0)
    {
        return 1;
    }
    else if(n%2!=0)
    {
        cnt[0]++;
        return(m*power(m,n-1,cnt));
    }
    else
    {
        cnt[0]++;
        return(pow(m,n/2)*power(m,n/2,cnt));
    }

}

int main(void)
{
    int m,n,cnt[]={0};
    unsigned long long int result=1;
    printf("Enter base: ");
    scanf("%d",&m);
    printf("Enter power: ");
    scanf("%d",&n);
    if (m==0 && n==0) printf("Illegal input");
    if (m==0) 
    {
        printf("0, 0\n");
        exit(0);
    }
    if (n%2!=0) result=m*power(m,n-1,cnt);
    else if (n%2==0)
    {
        result=power(m,n/2,cnt);
        result*=result;
    }
    printf("%llu, %d\n",result,cnt[0]);
    return 0;
}

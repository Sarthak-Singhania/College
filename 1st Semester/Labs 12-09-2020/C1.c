#include<stdio.h>
int main()
{
  int n,i,cnt=0,sum=0;
  scanf("%d", &n);
  for(i=2;i<n;i++)
  {
    if (n%i==0)
    {
      cnt++;
      sum+=i;
    }
  }
  if(sum!=0)
  {
    printf("%d\n", sum);
  }
  else
  {
    printf("%s\n", "Prime");
  }
}

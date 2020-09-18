#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    if(n<3)
    {
      printf("Illegal input\n");
    }
    else
    {
      int arr[n];
      for(i=0;i<n;i++)
      {
          scanf("%d", &arr[i]);
      }
      int i=0,cnt=0;

      for(i=0;i<n;i++)
      {
        if(arr[i]%5==0)
        {
          cnt++;
        }
      }
      printf("Divisible: %d, Not Divisible: %d\n",cnt,n-cnt);
    }
    return 0;
}

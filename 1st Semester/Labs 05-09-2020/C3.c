#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}
void bubbleSort(int arr[], int n)
{
   int i,j,cnt;
   for(i=0;i<n-1;i++)
   {
     for(j=0;j<n-i-1;j++)
         if (arr[j]>arr[j+1])
         {
          cnt++;
          swap(&arr[j], &arr[j+1]);
         }
   }
   printf("Sorted array: [");
   for(i=0;i<n-1;i++)
   {
     printf("%d ", arr[i]);
   }
   printf("%d]\n", arr[n-1]);
   printf("No. of exchanges: %d\n", cnt);
}
int main()
{
  int i,n;
  scanf("%d",&n);
  if(n==0)
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
    printf("Unsorted array: [");
    for(i=0;i<n-1;i++)
    {
      printf("%d ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);
    bubbleSort(arr,n);
  }
    return 0;
}

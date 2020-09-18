#include <stdio.h>

int main(void)
{
    int n,i;
    printf("Lenght of array: ");
    scanf("%d",&n);
    float avg,sum=0.0,arr[n];
    printf("Enter numbers separated by space: ");
    for(i=0;i<n;i++)
    {
        scanf("%f", &arr[i]);
        sum += arr[i];
    }
    avg=sum/n;
    printf("Average: %.2f\n",avg);
    float ar[n];
    int in;
    for(i=0;i<n;i++) ar[i]=arr[n]-avg;
    float smallest;
    smallest = ar[0];
 
   for (i = 0; i < n; i++) {
      if (ar[i] > smallest) {
        smallest = ar[i];
        in=n;
      }
   }
   printf("Farthest: %.2f\n", arr[in]);
}
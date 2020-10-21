#include <stdio.h>
int stat(float *array,int n,float *a)
{
    float avg,sum=0,max,min;
    for(int i=0;i<n;i++) sum+=*(array+i);
    avg=sum/n;
    for (int c=0;c<n; c++) if (a[c]>max) max=a[c];
    min=max;
    for (int j=0;j<n; j++) if (a[j]<min) min=a[j];
    printf("Average: %.2f\nMax number: %.2f\nMin number: %.2f\n",avg,max,min);
    return 0;
}

int main()
{
    float a[100],b[100],*array1,*max;
    int N;
    printf("Enter size of array: ");
    scanf("%d",&N);
    printf("Enter matrix elements (separated by spaces): ");
    for(int i=0;i<N;i++) scanf("%f",&a[i]);
    array1=a;
    stat(array1,N,a);
}

#include <stdio.h>

void swap(int *xp, int *yp) 
{ 
    int temp=*xp; 
    *xp=*yp; 
    *yp=temp; 
}

void selectionSort(int arr[], int n) 
{ 
    int i,j,min_idx; 
    for (i=0;i<n-1;i++)
    { 
        min_idx=i; 
        for(j=i+1;j<n;j++) 
            if(arr[j]<arr[min_idx]) 
                min_idx=j; 
        swap(&arr[min_idx],&arr[i]); 
    } 
} 

int main()
{
    int n;
    printf("Size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<n/2;i++) 
        if(arr[n/2]<arr[i])
            swap(&arr[n/2],&arr[i]);
    for(int i=(n/2+1);i<n;i++) 
        if(arr[n/2]<arr[i])
            swap(&arr[n/2],&arr[i]);
    printf("Largest element = %d\n", arr[n/2]);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}
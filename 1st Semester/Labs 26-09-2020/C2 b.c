#include<stdio.h>
#include<stdlib.h>
#include"elimination.h"
#define N 20

void printArray(float a[][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) printf("%.2f ",a[i][j]);
        printf("\n");
    }
}

int main(void)
{
    float a[N][N],inv[N][N],d;
    int n;
    printf("Dimensions: ");
    scanf("%d",&n);
    printf("Enter matrix elements: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) scanf("%f",&a[i][j]);
    }
    d=determinant(a,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) inv[j][i]=cofactor(a,n,i,j)/d;
    }
    printf("Inverse of A\n");
    printArray(inv,n);
    return 0;
}
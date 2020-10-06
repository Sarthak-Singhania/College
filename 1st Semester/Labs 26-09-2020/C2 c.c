#include<stdio.h>
#include<stdlib.h>
#define N 20

void eliminate(float a[][N],int n)
{
	for(int prow=0;prow<n;prow++)
	{
		if(a[prow][prow]==0.0)
		{
			int k;
			for(k=prow+1;k<n;k++)
				if(a[k][prow]!=0) break;
			float temp;
			for(int j=prow;j<n;j++)
			{
				temp=a[prow][j];
				a[prow][j]=a[k][j];
				a[k][j]=temp;
			}
		}
		for(int erow=0;erow<n;erow++)
		{
			if(erow!=prow)
			{
				float c=-a[erow][prow]/a[prow][prow];
				for(int j=prow;j<=n;j++) a[erow][j]+=c*a[prow][j];
			}
		}
	}
	return;
}

int main(void)
{
	float a[N][N],x[N];
	int n;
	printf("Dimensions: ");
	scanf("%d",&n);
	printf("Elements of matrix: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++) scanf("%f",&a[i][j]);
	}
	eliminate(a,n);
	for(int row=0;row<n;row++) x[row]=a[row][n]/a[row][row];
	for(int row=0;row<n;row++) printf("X%d=%.2f\n",row+1,x[row]);
	return 0;
}
#include <stdio.h>

int N;

int CoFactor(int mat[N][N],int temp[N][N],int p,int q,int n) 
{ 
    int i=0,j=0;
    for(int row=0;row<n;row++) 
    { 
        for(int col=0;col<n;col++) 
        {
            if(row!=p && col!=q) 
            { 
                temp[i][j++]=mat[row][col];
                if(j==n-1) 
                { 
                    j=0;
                    i++;
                } 
            } 
        } 
    } 
}
int determinant(int mat[N][N],int n) 
{ 
    int D=0;
    if(n==1) 
        return mat[0][0];
    int temp[N][N];
    int sign=1;
    for(int f=0;f<n;f++) 
    {
        CoFactor(mat,temp,0,f,n);
        D+=sign*mat[0][f]*determinant(temp,n-1);
        sign=-sign;
    } 
  
    return D;
}

int main() 
{
    scanf("%d",&N);
    int mat[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Determinant of the matrix is: %d\n",determinant(mat,N));
    return 0;
} 
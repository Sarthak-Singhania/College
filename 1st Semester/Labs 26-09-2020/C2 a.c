#include<stdio.h>
#include<math.h>
int gaussian(int m, int n, double a[m][n]){
    int cnt=0;
    for(int i=0;i<m-1;i++)
    {
        for(int k=i+1;k<m;k++)
        {
            if(fabs(a[i][i])<fabs(a[k][i]))
            {
                cnt++;
                for(int j=0;j<n;j++)
                {                
                    double temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        for(int k=i+1;k<m;k++)
        {
            double  term=a[k][i]/a[i][i];
            for(int j=0;j<n;j++) a[k][j]=a[k][j]-term*a[i][j];
        }
    }
    return cnt;       
}
double determinant(int n, double a[n][n])
{
    double det=1;
    int i;
    int cnt=gaussian(n,n,a);
    for(i=0;i<n;i++)
    {
        det*=a[i][i];
    }
    return det*pow(-1,cnt);
}
int main()
{
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d",&n);
    double a[n][n];
    printf("\nEnter the elements of matrix: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lf",&a[i][j]);
        }
    }
    printf("\nThe determinant is: %.2f\n",determinant(n,a));    
}
#include<stdio.h>
#include<math.h>
double determinant(int n, double a[n][n]){
    double det=1;
    int i;
    int swapCount=gaussElimination(n,n,a);
    for(i=0;i<n;i++){
        det =det*a[i][i];
    }
    return det*(-1,swapCount);
}
int gaussElimination(int m, int n, double a[m][n]){
    int i,j,k;
    int swapCount=0;
    for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            if(fabs(a[i][i])<fabs(a[k][i])){
                swapCount++;
                for(j=0;j<n;j++){                
                    double temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        for(k=i+1;k<m;k++){
            double  term=a[k][i]/ a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }
    }
    return swapCount;       
}
void readMatrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&matrix[i][j]);
        }
    } 
}
void printMatrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%lf\t",matrix[i][j]);
        }
        printf("\n");
    } 
}
void copyMatrix(int m, int n, double matrix1[m][n], double matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    } 
}
 
int main(){
    int n,i,j;
    printf("Enter the order of the matrix:\n(No. of rows/columns (n))\n");
    scanf("%d",&n);
    double a[n][n];
    printf("\nEnter the elements of matrix:\n");
    readMatrix(n,n,a); 
    printf("\nThe determinant using Gauss Eliminiation is:\n\n%.2f\n",determinant(n,a));    
}
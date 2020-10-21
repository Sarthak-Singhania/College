#include <stdio.h>
#define N 10

float cofactor(float arr[][N], int k, int dim);

void printArray(float a[][N], int n) {
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      printf("%.2f ", a[i][j]);
    printf("\n");
  }
}

float determinant(float a[][N], int n) {
  float d=0.0;
  if (n==1) d=a[0][0];
  else if (n==2) d=a[0][0]*a[1][1]-a[0][1]*a[1][0];
       else {
           for (int j=0; j<n; j++)
             d+=a[0][j]*cofactor(a, j, n);//expand using row 0
       }
  return d;
}

float cofactor(float a[][N], int j, int n){
  int sign=(j%2==0)?1:-1;
  /*C(i,j)=(-1)^(i+j)*Minor(i,j)
  Minor(i,j)=determinant(a') where a' is obtained by removing
  row i and column j from a. Here i is always 0.*/
  float b[N][N];
  for (int row=1; row<n; row++) {
    for (int col=0; col<j; col++)
      b[row-1][col]=a[row][col];
    for (int col=j+1; col<n; col++)
      b[row-1][col-1]=a[row][col];
  }
  return (sign*determinant(b, n-1));
}

int main(void) {
  float a[N][N], d;
  int n;//dimension of matrix
  printf("Give dimension of square matrix = ");
  scanf("%d", &n);
  printf ("Give the coefficients row-wise sep. by white space\n");
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      scanf("%f", &a[i][j]);
  printArray(a, n);
  d=determinant(a, n);
  printf("Determinant = %.2f\n", d);
  return 0;
}

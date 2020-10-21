#include <stdio.h>

#define N 20

void printArray(float a[][N], int n) {
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      printf("%.2f ", a[i][j]);
    printf("\n");
  }
}

int eliminate(float a[][N], int n){
  int exchanges=0;//every exchange flips determinant sign
  for (int row=0; row<n-1; row++) {
    for (int i=row+1; i<n; i++) {
      if (a[row][row]==0.0) {
        //exchange with a higher row no. say k where a[k][row] not 0.
        int k;
        for (k=row+1; k<n; k++)
          if (a[k][row]!=0) break;
        float temp;
        exchanges++;
        for (int col=row; col<=n; col++) {
          temp=a[row][col];
          a[row][col]=a[k][col];
          a[k][col]=temp;
        }
      }
      float c=-a[i][row]/a[row][row];
      a[i][row]=0.0;
      for (int j=row+1; j<n; j++)
        a[i][j]+=c*a[row][j];
    }
  }
  return exchanges;
}

int main(void) {
  float a[N][N], x[N];
  int n;//dimension of square matrix
  printf("Give dimension of square matrix = ");
  scanf("%d", &n);
  printf ("Give the coefficients row-wise sep. by white space\n");
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      scanf("%f", &a[i][j]);
  int exchanges=eliminate(a, n);//no. of exchanges during triangularization
  printf("\nArray after elimination\n");
  printArray(a, n);
  //Note that for a triangular matrix if we calculate the determinant
  //using the Laplace expansion it will be a product of the diagonal elements
  float det=((exchanges%2)==0)?1:-1;
  for (int i=0; i<n; i++)
    det*=a[i][i];
  printf("Determinant = %.2f\n", det);
  return 0;
}

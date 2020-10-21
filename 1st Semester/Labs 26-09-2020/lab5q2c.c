#include <stdio.h>
#include <stdlib.h>
#define N 20

/*Assumes linear system has unique solution. If matrix is
singular exits with a message.*/

void printArray(float a[][N], int rows, int cols) {
  for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++)
      printf("%.2f ", a[i][j]);
    printf("\n");
  }
}

void eliminate(float a[][N], int n){
  for (int prow=0; prow<n; prow++) {
    //prow is the row for current pivot element
    if (a[prow][prow]==0.0) {
      /* Pivot is 0, exchange with a higher row number,
      say k, where a[k][row] not 0.*/
      int k;
      for (k=prow+1; k<n; k++)
        if (a[k][prow]!=0) break;
      if (k==n) {//unable to find pivot
        printf("Unable to reduce matrix. Singular.\n");
        exit(0);
      }
      //exchange row k and row prow
      float temp;
      for (int j=prow; j<n; j++) {
        temp=a[prow][j];
        a[prow][j]=a[k][j];
        a[k][j]=temp;
      }
    }
    for (int erow=0; erow<n; erow++) {
      //erow is the current elimination row
      if (erow!=prow) {
        float c=-a[erow][prow]/a[prow][prow];
        for (int j=prow; j<=n; j++)
          a[erow][j]+=c*a[prow][j];
      }
    }
  }
  return;
}

int main(void) {
  float a[N][N], x[N];
  int n;//no. of unknowns
  printf("Give no. of unknowns = ");
  scanf("%d", &n);
  printf ("Give the coefficients and RHS row-wise sep. by white space\n");
  for (int i=0; i<n; i++)
    for (int j=0; j<=n; j++)
      scanf("%f", &a[i][j]);
  eliminate(a, n);
  printf("\nArray after elimination\n");
  printArray(a, n, n+1);
  //backsubstitution is easy
  for (int row=0; row<n; row++)
    x[row]=a[row][n]/a[row][row];
  printf("Soln. of linear equations\n");
  for (int row=0; row<n; row++)
    printf("X%d = %.2f\n", row+1, x[row]);
  return 0;
}

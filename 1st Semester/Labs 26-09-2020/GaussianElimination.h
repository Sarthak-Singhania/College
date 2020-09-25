#include <stdio.h>
#include <stdlib.h>
#define N 20

/*Assumes linear system has unique solution*/

void printArray(float a[][N], int n) {
  for (int i=0; i<n; i++) {
    for (int j=0; j<=n; j++)
      printf("%.2f ", a[i][j]);
    printf("\n");
  }
}

void eliminate(float a[][N], int n){
  for (int row=0; row<n-1; row++) {
    for (int i=row+1; i<n; i++) {
      if (a[row][row]==0.0) {
        //exchange with a higher row no. say k where a[k][row] not 0.
        int k;
        for (k=row+1; k<n; k++)
          if (a[k][row]!=0) break;
        if (k==n) {
          printf("Unable to triangularize. No unique solution.\n");
          exit(0);
        }
        float temp;
        for (int col=row; col<=n; col++) {
          temp=a[row][col];
          a[row][col]=a[k][col];
          a[k][col]=temp;
        }
      }
      float c=-a[i][row]/a[row][row];
      a[i][row]=0.0;
      for (int j=row+1; j<=n; j++)
        a[i][j]+=c*a[row][j];
    }
  }
  return;
}

void backsubstitute(float a[][N], float x[], int n) {
  for (int row=n-1; row>-1; row--) {
    float sum=0;
    for (int j=row+1; j<n; j++)
      sum+=x[j]*a[row][j];
    x[row]=(a[row][n]-sum)/a[row][row];
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
  printArray(a, n);
  backsubstitute(a, x, n);
  printf("\nLinear eqn. solns after backsubstitution\n");
  for (int i=0; i<n; i++) {
    printf("x%d = %.2f\n", i+1, x[i]);
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
//#include "lab5q2a.h"
#define N 20

float flabs(float x) {return ((x<0.0)?-x:x);}

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

float determinant(float a[][N], int n) {
  //Computes determinant using order of n^3 steps.
  //Uses library function eliminate to triangularize matrix
  if (n==1) return a[0][0];
  if (n==2) return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
  float d, b[N][N];
  //Make a copy of matrix a to avoid changing a.
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      b[i][j]=a[i][j];
  d=((eliminate(b, n)%2)==0)?1:-1;
  for (int i=0; i<n; i++)
    d*=b[i][i];
  return d;
}

float cofactor(float a[][N], int n, int i, int j) {
  float aprime[N][N];
  //Construct A' by removing row i, col j from A
  for (int r=0; r<i; r++) {
    for (int c=0; c<j; c++)
      aprime[r][c]=a[r][c];
    for (int c=j+1; c<n; c++)
      aprime[r][c-1]=a[r][c];
  }
  for (int r=i+1; r<n; r++) {
    for (int c=0; c<j; c++)
      aprime[r-1][c]=a[r][c];
    for (int c=j+1; c<n; c++)
      aprime[r-1][c-1]=a[r][c];
  }
  return (((((i+j)%2)==0)?1:-1)*determinant(aprime, n-1));
}

int main(void) {
  float a[N][N], ainv[N][N], d;
  int n;//dimension of square matrix
  printf("Give dimension of square matrix = ");
  scanf("%d", &n);
  printf ("Give the coefficients row-wise sep. by white space\n");
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      scanf("%f", &a[i][j]);
  d=determinant(a, n);
  if (flabs(d)<1.0e-10) {
    printf("Determinant is near 0. Unable to calculate inverse.\n");
    exit(0);
  }
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      ainv[j][i]=cofactor(a, n, i, j)/d;
  printf("Orginal array A\n");
  printArray(a, n);
  printf("Inverse of A\n");
  printArray(ainv, n);
  return 0;
}

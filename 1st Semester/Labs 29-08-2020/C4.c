#include<stdio.h>

int main(void){
  int len, start, mini, i, max;
  int arr[5]={3,2,1,5,4};
  len=5;
  for(start=0;start<len;start=start+1){
    mini=start;
    for(i=0;i<len;i=i+1){
      if (arr[i]<arr[mini]) mini=i;
    }
  }
  for(start=0;start<len;start=start+1){
    max=start;
    for(i=0;i<len;i=i+1){
      if (arr[i]>arr[max]) max=i;
    }
  }
  printf("Maximum of unsorted seq is = %d, its index is=%d\n",arr[max],max);
  printf("Minimum of unsorted seq is = %d, its index is=%d\n",arr[mini],mini);
}

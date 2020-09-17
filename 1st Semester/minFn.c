#include<stdio.h>

void printa(int arr[], int start, int len){
  printf("[");
  for(int i=start;i<len;i+=1)
    printf("%d,",arr[i]);
  printf("\b]");
  return;
}

int minIndex(int arr[], int start, int len){
  int mini=start, min=arr[start];
    for(int i=start; i<len; i+=1){
      if (arr[i]<arr[mini]) mini=i;
    }
  return mini;
}

int main(void){
  int len, start, mini, arr[]={8,5,6,7,4,3,2};
  len=7;
  printf("\nGive start of arrary (between 0 and %d) =",len-1);
  scanf("%d",&start);
  if (start<0 || start>len-1) {
    printf("Illegal input - exiting\n");
    return 0;
  }
  printf("\nSequence = ");
  printa(arr,0,len);
  printf("\n");
  printf("Subsequence for finding min index = ");
  printa(arr,start,len);
  printf("\n");
  mini=minIndex(arr,start,len);
  printf("Min index (in original sequence = %d\n",mini);
  printf("Minimum value in subsequence = %d\n",arr[mini]);
  return 0;
}

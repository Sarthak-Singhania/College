#include<stdio.h>

void printa(int arr[], int start, int len){
  printf("[");
  for(int i=start;i<len;i+=1)
    printf("%d,",arr[i]);
  printf("\b]");
  return;
}
int minindex(int arr[], int start, int len){
  int mini=start;
  for(int i=start; i<len; i+=1){
    if (arr[i]>arr[mini]) mini=i;
  }
  return mini;
}
void selsort(int arr[], int l){
  if (l==0) {
    printf("Empty sequence");
    return;
  }
  if (l>1) {
    for(int i, start=0; start<l; start+=1){
      i=minindex(arr,start,l);
      if(i!=start){
        int temp=arr[i];
        arr[i]=arr[start];
        arr[start]=temp;
      }
    }
  }
  return;
}
int main(void) {
  int len, arr[]={8,5,6,7,4,3,2};
  len=7;
  printf("\nUnsorted sequence ");
  printa(arr,0,len);
  printf("\n");
  selsort(arr, len);
  printf("\nSorted sequence ");
  printa(arr,0,len);
  printf("\n");
  return 0;
}

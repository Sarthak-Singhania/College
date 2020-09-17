#include<stdio.h>

int main(void){
  int len, start, mini, cnt=0;
  int i,temp;// temp variable used to do exchange, i is looping variable
  //len is the length of the seq
  //mini is the index of the minimum element in the unsorted sequence
  /* start is the index for start of the unsorted sequence.
  The seq to the left of start is sorted.*/
  int arr[]={8,5,6,7,4,3,2};//arr is the unsorted seq of length 5
  len=7;
  for(start=0;start<len;start=start+1){
    /*Code upto line 17 finds the index of the minimum element in the
    unsorted sequence. This is similar to the code in min.c.
    */
    mini=start;//At start assumes mini=start
    for(i=start;i<len;i=i+1){
      //Finds the index of min element in unsorted seq.
      if (arr[i]<arr[mini]) mini=i;
    }
    if (mini!=start) {
      /*If mini and start are not equal exchange the values at positions
      start and mini in the sequence. */
      temp=arr[mini];
      arr[mini]=arr[start];
      arr[start]=temp;
      cnt++;
    }
  }
  printf("%s","Sorted sequence = [");
  for (i=0;i<len;i=i+1)
    printf("%d,",arr[i]);
  printf("%s","\b]\n");//\b prints backspace removing last comma.
  printf("%d\n", cnt);
  return 0;
}
//####################################################################################################################################################################
//The sequences for minimum number of exchanges {1,2,3,4,5}: 0
//The sequences for minimum number of exchanges {4,3,5,2,1}: 4

#include <stdio.h>

int main(void) {
  int a[3][3],rows=3,cols=3;
  int i1,i2,i3,j1,j2,j3,v,s,i[4]={0};
  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
  v=a[0][0];
  for (i1=0;i1<rows;i1++)
    for(j1=0;j1<cols;j1++)
      for(i2=i1;i2<rows;i2++)
        for(j2=j1;j1<cols;j2++)
        {
          s=0;
          for(i3=i1;i3<=i2;i3++)
            for(j3=j1;j3<=j2;j3++)
              s+=a[i3][j3];
          if(s>v) {v=s; i[0]=i1; i[1]=j1; i[2]=i2; i[3]=j2;}
        }
  printf("%d\n",v);
  printf("(%d, %d), (%d, %d)\n",i[0],i[1],i[2],i[3]);
  for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
      {
        printf("%d",a[i][j]);
      }
    }
}

// #include <stdio.h>
// int func(int a,int b)
// {
//   while(a>1 && b>1 && a!=b)
//   {
//     if(b>a) b-=a;
//     else if(b<a) a-=b;    
//   }
//   return a;
// }

// int main()
// {
//   printf("%d\n",func(57,152));
// }

// int main()
// {
//   int n=0;
//   switch (n)
//   {
//   case 0: printf("0"); case 1: printf("1"); break; case 2: printf("2"); break;
//   default:
//     printf("-1");
//   }
// }
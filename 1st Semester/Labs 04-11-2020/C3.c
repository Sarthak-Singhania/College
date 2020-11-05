#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int count_f1()
{
    FILE *file;
    char c;
    file=fopen("test3.txt","r");
    int cnt=0;
    while(1>0)
    {
        c=fgetc(file);
        if(c!=EOF) cnt+=1;
        else break;
    }
    return cnt;
}

int count_f2()
{
    FILE *file;
    char c;
    file=fopen("check1.txt","r");
    int cnt=0;
    while(1>0)
    {
        c=fgetc(file);
        if(c!=EOF) cnt+=1;
        else break;
    }
    return cnt;
}

int main()
{
    FILE *fp;
    fp=fopen("test3.txt","r");
    char arr[1000],check1[100];
    int nchar,j,len=0,start;
    nchar=count_f1();

    for(int i=0;i<nchar;i++) arr[i]=fgetc(fp);
    fclose(fp);
    FILE *pf;
    pf=fopen("check1.txt","w");
    for(int i=0;i<nchar;i++)
    {
        if(isdigit(arr[i])==0) continue;
        else
        {
            if(arr[i+2]=='-' && arr[i+5]=='-')
            {
                for(int p=i;p<i+8;p++) fprintf(pf,"%c",arr[p]);
                fprintf(pf,"\n");
            }
        }
    }
    fclose(pf);
    int nchar1;
    char c;
    nchar1=count_f2();
    FILE *fop;
    fop=fopen("check1.txt","r");
    for(int i=0;i<nchar;i++)
    {
        check1[i]=fgetc(fop);
        if(check1[i]=='\n') len++;
    }
    fclose(fop);
    printf("\n");
    int day[len*2],month[len*2],year[len*2],date[nchar1],dayval[len],monthval[len],yearval[len];
    for(j=0;j<nchar1;j++) date[j]=check1[j]-'0';
    for(int i=0;i<len;i++)
    {
        start=i*9;
        day[i*2]=date[start];
        day[i*2+1]=date[start+1];
    }
    for(int i=0;i<len;i++) dayval[i]=( day[i*2] * 10 ) + day[i*2+1];
    for(int i=0;i<len;i++)
    {
        start=i*9+3;
        month[i*2]=date[start];
        month[i*2+1]=date[start+1];
    }
    for(int i=0;i<len;i++) monthval[i]=(month[i*2]*10)+month[i*2+1];
    for(int i=0;i<len;i++)
    {
        start=i*9+6;
        year[i*2]=date[start];
        year[i*2+1]=date[start+1];
    }
    for(int i=0 ;i<len;i++) yearval[i]=(year[i*2]*10)+year[i*2+1];
    FILE *finalfp;
    finalfp=fopen("dates.txt","w");
    int is_leap=0;
    int is_valid=1;
    for (int i=0;i<len;i++)
    {
        if (yearval[i]%4==0) is_leap=1;
        if (monthval[i]>=1 && monthval[i]<=12)
        {
            if (monthval[i]==2)
            {
                if (is_leap && dayval[i]==29) is_valid=1;
                else if (dayval[i]>28) is_valid=0;
            }
            else if (monthval[i]==4 || monthval[i]==6 || monthval[i]==9 || monthval[i]==11)
            {
               if (dayval[i]>30) is_valid=0;
            }
            else if (dayval[i]>31) is_valid=0;
        }
        else is_valid=0;
        if (is_valid) fprintf(finalfp,"%.2d-%.2d-%.2d\n",dayval[i],monthval[i],yearval[i]);
        else continue;
    }
}
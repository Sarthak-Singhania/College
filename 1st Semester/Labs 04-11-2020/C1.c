#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file,*file1;
    char ch;
    int characters,words,lines;
    file=fopen("test1.txt","r");
    characters=words=lines=0;
    while ((ch=fgetc(file)) != EOF)
    {
        characters++;
        if (ch=='\n' || ch=='\0') lines++;
        if (ch==' ' || ch=='\t' || ch=='\n' || ch=='\0') words++;
    }
    if (characters > 0)
    {
        words++;
        lines++;
    }
    fclose(file);
    file1=fopen("stat.txt","w");
    fprintf(file1,"Total characters: %d\nTotal words: %d\nTotal lines: %d\n",characters,words,lines);
    fclose(file1);
    return 0;
}
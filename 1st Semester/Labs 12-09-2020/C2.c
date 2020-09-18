#include <stdio.h>

int main(void)
{
	char a;
	a=getchar();
	int dd=a-48;
	a=getchar();
	dd=dd*10+a-48;
	a=getchar();
	int mm=0;
	a=getchar();
	mm=a-48;
	a=getchar();
	mm=mm*10+a-48;
	a=getchar();
	int yy=0;
	for(int i=0;i<4;i++)
		{
			a=getchar();
			yy=yy*10+a-48;
		}
    switch (mm)
    {
    case 1:
        printf("Jan ");
        break;
    case 2:
        printf("Feb ");
        break;
    case 3:
        printf("Mar ");
        break;
    case 4:
        printf("Apr ");
        break;
    case 5:
        printf("May ");
        break;
    case 6:
        printf("Jun ");
        break;
    case 7:
        printf("Jul ");
        break;
    case 8:
        printf("Aug ");
        break;
    case 9:
        printf("Sep ");
        break;
    case 10:
        printf("Oct ");
        break;
    case 11:
        printf("Nov ");
        break;
    case 12:
        printf("Dec ");
        break;
    default:
        break;
    }
	printf("%d",dd);
    switch (dd)
    {
    case 1: case 21: printf("st "); break;
    case 2: case 22: printf("nd "); break;
    case 3: case 23: printf("rd "); break;
    default:
        printf("th ");
        break;
    }
	printf("%d\n",yy);	
	return 0;
}
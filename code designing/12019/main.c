#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        while(x--)
        {
            int month,date,a;
            scanf("%d %d",&month,&date);
            if(month>12||month<1)
                break;
            if(date>31||date<1)
                break;
            if(month==1||month==10)
            {
                a=date%7;
                if(a==0)
                    printf("Friday");
                else if(a==1)
                    printf("Saturday");
                else if(a==2)
                    printf("Sunday");
                else if(a==3)
                    printf("Monday");
                else if(a==4)
                    printf("Tuesday");
                else if(a==5)
                    printf("Wednesday");
                else if(a==6)
                    printf("Thursday");
            }
            else if(month==2||month==3||month==11)
            {
                a=date%7;
                if(a==0)
                    printf("Monday");
                else if(a==1)
                    printf("Tuesday");
                else if(a==2)
                    printf("Wednesday");
                else if(a==3)
                    printf("Thursday");
                else if(a==4)
                    printf("Friday");
                else if(a==5)
                    printf("Saturday");
                else if(a==6)
                    printf("Sunday");
            }
            else if(month==4||month==7)
            {
                a=date%7;
                if(a==0)
                    printf("Thursday");
                else if(a==1)
                    printf("Friday");
                else if(a==2)
                    printf("Saturday");
                else if(a==3)
                    printf("Sunday");
                else if(a==4)
                    printf("Monday");
                else if(a==5)
                    printf("Tuesday");
                else if(a==6)
                    printf("Wednesday");
            }
            else if(month==5)
            {
                a=date%7;
                if(a==0)
                    printf("Saturday");
                else if(a==1)
                    printf("Sunday");
                else if(a==2)
                    printf("Monday");
                else if(a==3)
                    printf("Tuesday");
                else if(a==4)
                    printf("Wednesday");
                else if(a==5)
                    printf("Thursday");
                else if(a==6)
                    printf("Friday");
            }
            else if(month==6)
            {
                a=date%7;
                if(a==0)
                    printf("Tuesday");
                else if(a==1)
                    printf("Wednesday");
                else if(a==2)
                    printf("Thursday");
                else if(a==3)
                    printf("Friday");
                else if(a==4)
                    printf("Saturday");
                else if(a==5)
                    printf("Sunday");
                else if(a==6)
                    printf("Monday");
            }
            else if(month==8)
            {
                a=date%7;
                if(a==0)
                    printf("Sunday");
                else if(a==1)
                    printf("Monday");
                else if(a==2)
                    printf("Tuesday");
                else if(a==3)
                    printf("Wednesday");
                else if(a==4)
                    printf("Thursday");
                else if(a==5)
                    printf("Friday");
                else if(a==6)
                    printf("Saturday");
            }
            else if(month==9||month==12)
            {
                a=date%7;
                if(a==0)
                    printf("Wednesday");
                else if(a==1)
                    printf("Thursday");
                else if(a==2)
                    printf("Friday");
                else if(a==3)
                    printf("Saturday");
                else if(a==4)
                    printf("Sunday");
                else if(a==5)
                    printf("Monday");
                else if(a==6)
                    printf("Tuesday");
            }
        }
    }

    return 0;
}

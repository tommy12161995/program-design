#include <stdio.h>
#include <stdlib.h>
#include <string.h>
leapyear(int a)
{
    if(a%4==0&&a%100!=0)
        return 0;
    else if(a%4!=0)
        return 1;
    else if(a%100==0&&a%400!=0)
        return 1;
}
monththink(int b)
{
    if(b==4||b==6||b==9||b==11)
        return 1;
    else if(b==1||b==3||b==5||b==7||b==8||b==10)
        return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int flag=0;
        while(n--)
        {
            flag++;
            int year,date,len,input_2,month;
            char input_1[20];
            scanf("%d",&year);
            fgets(input_1,20,stdin);
            len=strlen(input_1);
            date=(input_1[len-2]-48)+(input_1[len-3]-48)*10;
            scanf("%d",&input_2);
            while(1)
            {
                if(input_2<365&&leapyear(year)==1)
                    break;
                else if(input_2<366&&leapyear(year)==0)
                    break;
                else if(leapyear(year)==1)
                {
                    input_2-=365;
                    year++;
                }
                else if(leapyear(year)==0)
                {
                    input_2-=366;
                    year++;
                }
            }
            switch(input_1[1])
            {
            case 'J':
                if(input_1[2]='a')
                    month=1;
                if(input_1[2]='u')
                {
                    if(input_1[3]='n')
                        month=6;
                    else if(input_1[3]='l')
                        month=7;
                }
                break;
            case 'F':
                month=2;
                break;
            case 'M':
                if(input_1[3]='r')
                    month=3;
                else if(input_1[3]='y')
                    month=5;
                break;
            case 'A':
                if(input_1[2]='r')
                    month=4;
                else if(input_1[2]='u')
                    month=8;
                break;
            case 'S':
                month=9;
                break;
            case 'O':
                month=10;
                break;
            case 'N':
                month=11;
                break;
            case 'D':
                month=12;
                break;
            }
            date+=input_2;

            while(1)
            {
                if(date>30&&monththink(month)==1)
                {
                    date-=30;
                    month++;
                }
                else if(date>31&&monththink(month)==0)
                {
                    date-=31;
                    month++;
                }
                else if(month==2&&date>29)
                {
                    if(leapyear(year)==1)
                    {
                        date-=28;
                        month++;
                    }
                    else if(leapyear(year)==0)
                    {
                        date-=29;
                        month++;
                    }

                }
                else if(month==12&&date>31)
                {
                    date-=31;
                    month=1;
                    year++;
                }
                else
                    break;
            }
            switch(month)
            {
            case 1:
                printf("Case %d: %.4d-January-%.2d\n",flag,year,date);
                break;
            case 2:
                printf("Case %d: %.4d-February-%.2d\n",flag,year,date);
                break;
            case 3:
                printf("Case %d: %.4d-March-%.2d\n",flag,year,date);
                break;
            case 4:
                printf("Case %d: %.4d-April-%.2d\n",flag,year,date);
                break;
            case 5:
                printf("Case %d: %.4d-May-%.2d\n",flag,year,date);
                break;
            case 6:
                printf("Case %d: %.4d-June-%.2d\n",flag,year,date);
                break;
            case 7:
                printf("Case %d: %.4d-July-%.2d\n",flag,year,date);
                break;
            case 8:
                printf("Case %d: %.4d-August-%.2d\n",flag,year,date);
                break;
            case 9:
                printf("Case %d: %.4d-September-%.2d\n",flag,year,date);
                break;
            case 10:
                printf("Case %d: %.4d-October-%.2d\n",flag,year,date);
                break;
            case 11:
                printf("Case %d: %.4d-November-%.2d\n",flag,year,date);
                break;
            case 12:
                printf("Case %d :%.4d-December-%.2d\n",flag,year,date);
                break;
            }
        }
    }
    return 0;
}

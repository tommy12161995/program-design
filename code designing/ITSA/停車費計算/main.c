#include <stdio.h>
#include <stdlib.h>

int main()
{
   int time1_hour,time1_min,time2_hour,time2_min;
   while(scanf("%d %d %d %d",&time1_hour,&time1_min,&time2_hour,&time2_min)!=EOF)
   {
       int sum_time=(time2_hour*60+time2_min)-(time1_hour*60+time1_min);
       int sum=0,flag=0;
       while(sum_time>=30)
       {
           if(flag<4)
           {
               flag++;
               sum+=30;
               sum_time-=30;
           }
           else if(flag<8)
           {
               flag++;
               sum+=40;
               sum_time-=30;
           }
           else
           {
               flag++;
               sum+=60;
               sum_time-=30;
           }
       }
       printf("%d\n",sum);
   }
    return 0;
}

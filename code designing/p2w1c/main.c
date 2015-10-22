#include <stdio.h>
#include <stdlib.h>


struct part{
       int job;
       int deadline;
        };
int cmp(struct part *a,struct part *b);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int test;
            scanf("%d",&test);
            struct part job_number[test];
            int i;
            for(i=0;i<test;i++)
                scanf("%d",&job_number[i].job);
            for(i=0;i<test;i++)
                scanf("%d",&job_number[i].deadline);
            qsort(job_number,test,sizeof(struct part),cmp);
            for(i=0;i<test;i++)
            {
                if(job_number[i].deadline>=job_number[i].job)
                   job_number[i+1].job+=job_number[i].job;
                else if(job_number[i].deadline<job_number[i].job)
                   {
                       printf("No\n");
                       break;
                   }
                if(i==test-1)
                   {
                       printf("Yes\n");
                       break;
                   }
            }
        }
    }
    return 0;
}
int cmp(struct part *a,struct part *b)
{
     return (a->deadline)-(b->deadline);
}

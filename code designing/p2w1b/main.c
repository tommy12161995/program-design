#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int customer,i;
            scanf("%d",&customer);
            int box[customer];
            for(i=0;i<customer;i++)
                scanf("%d",&box[i]);
            qsort(box,customer,sizeof(int),cmp);
            int wait_time=0,people=customer;
            for(i=0;i<customer;i++)
                {
                    wait_time+=box[i]*(2*people-1);
                    people--;
                }
           printf("%d\n",wait_time);

        }
    }

    return 0;
}
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

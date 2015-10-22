#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    long long int money;
    long long int factor;
} part;
long long int cmp(const void *a,const void *b);
int main()
{
    int n,d;
    while(scanf("%d %d",&n,&d)!=EOF)
    {
        part friends[n];
        for(int i=0;i<n;i++)
            scanf("%I64d %I64d",&friends[i].money,&friends[i].factor);
        qsort(friends,n,sizeof(part),cmp);
        long long int max=0,temp=friends[0].factor,left=0;
        for(int i=1;i<n;i++)
        {
            if(i == n-1)
            {
                if(friends[i].money-friends[left].money<=d&&max<temp+friends[i].factor)
                    max=temp+friends[i].factor;
            }
            if(friends[i].money-friends[left].money>d)
            {
                if(max<temp)
                    max=temp;
                for(int j=left;j<i;j++)
                {
                    if(friends[i].money-friends[j].money>d)
                    {
                        temp-=friends[j].money;
                    }
                    else
                    {
                        left=j;
                        break;
                    }

                }
            }
            else
                temp+=friends[i].factor;
        }
        if(n == 1)
            max=friends[0].factor;
        printf("%I64d\n",max);
    }
    return 0;
}
long long int cmp(const void *a, const void *b)
{
    return ((part *)a)->money - ((part *)b)->money;
}

#include <stdio.h>
#include <stdlib.h>

int max(int a,int b);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
            break;
        int perform_time[n];
        for(int i=0;i<n;i++)
            scanf("%d",&perform_time[i]);
        int t1=0,t2=0,temp=0;
        for(int i=0;i<n;i++)
        {
            temp=t2+perform_time[i];
            t2=max(t1,t2);
            t1=temp;
            temp=0;
        }
        if(t1>=t2)
            printf("%d\n",t1);
        else
            printf("%d\n",t2);

    }
    return 0;
}
int max(int a,int b)
{
    if(a<=b)
        return b;
    else
        return a;
}

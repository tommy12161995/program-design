#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int num;
            scanf("%d",&num);
            int input[num];
            for(int i=0;i<num;i++)
                scanf("%d",&input[i]);
            int sum=0,max_sum=0;
            for(int i=0;i<num;i++)
            {
                sum+=input[i];
                if(sum>max_sum)
                    max_sum=sum;
                if(sum<0)
                    sum=0;
            }
            printf("%d\n",max_sum);
        }
    }
    return 0;
}

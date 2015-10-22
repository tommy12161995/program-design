#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int block;
            scanf("%d",&block);
            int number[block],i,j;
            for(i=0; i<block; i++)
            {
                scanf("%d",&number[i]);
            }
            int sum=0,max=0;
            for(i=0; i<block; i++)
            {
                for(j=i; j<block; j++)
                {
                    sum+=number[j];
                    if(sum>max)
                        max=sum;
                }
                sum=0;
            }
                printf("%d\n",max);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int num_1,num_2,check[200000]={0},total=0,weight,sum=0;
            scanf("%d %d",&num_1,&num_2);
            check[0]=1;
            for(int i=0;i<num_1;i++)
            {
                scanf("%d",&weight);
                for(int j=total;j>=0;j--)
                {
                    if(check[j] == 1)
                        check[j+weight]=1;
                }
                total+=weight;
            }
            for(int i=0;i<num_2;i++)
            {
                scanf("%d",&weight);
                if(check[weight] == 1)
                    sum++;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}

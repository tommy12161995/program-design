#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a,int b);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int people,leader;
            scanf("%d %d",&people,&leader);
            int input[2][people];
            input[1][0]=0;
            input[0][0]=leader;
            for(int i=1;i<people;i++)
                scanf("%d %d",&input[1][i],&input[0][i]);
            int value_max[2][people];
            memset(value_max,0,sizeof(value_max));
            for(int i=people-1;i>=0;i--)
            {
                if(i>=input[1][people-1])
                    value_max[0][i]=input[0][i];
                else
                {
                    value_max[0][i]=input[0][i];
                    for(int j=people-1;j>=0;j--)
                    {
                        if(input[1][j] == i+1)
                        {
                            value_max[0][i]+=value_max[1][j];
                            value_max[1][i]+=max(value_max[0][j],value_max[1][j]);
                        }
                        else if(input[1][j] < i+1)
                            break;
                    }
                }
                //printf("%d %d\n",value_max[0][i],value_max[1][i]);
            }
            if(value_max[0][0]>=value_max[1][0])
                printf("%d\n",value_max[0][0]);
            else
                printf("%d\n",value_max[1][0]);
        }
    }
    return 0;
}
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

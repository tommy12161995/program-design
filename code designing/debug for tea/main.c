#include <stdio.h>
#include <stdlib.h>

int main()
{
    int line;
    while(EOF!=scanf("%d",&line))
    {
        while(line--)
        {
                    int n;
        scanf("%d",&n);
        int i,j;
        int number[50]={0};
        for(i=0; i<n; i++)
        {
            scanf("%d",&number[i]);
        }
        int x=0,sum=0;
        for(i=0; i<n; i++)
        {
            if(number[i]>0)
            {
                j=i;
                while(j<n)
                {
                    x=x+number[j];
                    if(x>sum)
                    {
                        sum=x;
                    }
                    j++;
                }
            }
            x=0;
        }
        if(sum<0)
        printf("0\n");
        if(sum>=0)
        printf("%d\n",sum);
        x=0;
        sum=0;
        }

    }
return 0;
}

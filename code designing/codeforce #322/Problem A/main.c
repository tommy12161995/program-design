#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int different_day=0,same_day=0;
        while(1)
        {
            if(a>=1&&b>=1)
            {
                different_day++;
                a--;
                b--;
            }
            else
                break;
        }
        if(a == 0)
            same_day=b/2;
        else
            same_day=a/2;
        printf("%d %d\n",different_day,same_day);
    }
    return 0;
}

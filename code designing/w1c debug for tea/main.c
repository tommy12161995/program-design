#include <stdio.h>
#include <stdlib.h>

int main()
{
    int   numer,denom;
    while(EOF!=scanf("%d",&numer))
    {
        int   ans[100000]= {0};
        scanf("%d",&denom);
        if(denom==0)
            break;
        int count=1;
        while(1)
        {
            numer=(numer*10)%denom;
            if(ans[numer]==0)
            {
                ans[numer]=count;
                count++;
            }
            else if(ans[numer]!=0)
            {
                count=count-ans[numer];
                break;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int total,remainder,reverse,n,flag,sum;
    while(scanf("%lu",&total)!=EOF)
    {
        while(total--)
        {
            scanf("%lu",&n);
            flag=0;

            while(1)
            {
                reverse=0;
                sum=n;

                while(sum!=0)
                {
                    reverse=reverse*10+sum%10;
                    sum=sum/10;
                }
                if(reverse==n&&flag!=0)
                {
                    printf("%lu %lu\n",flag,reverse);
                    break;
                }
                else
                {
                    n=n+reverse;
                    flag++;
                }

            }

        }
    }
    return 0;
}

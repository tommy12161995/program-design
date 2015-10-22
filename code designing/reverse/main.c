#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int n,reverse=0,b=0,sum=0;
    int remainder=0,flag=0,total;
    while(scanf("%lu",&total)!=EOF)
    {
        while(total--)
        {
            scanf("%lu", &sum);
            reverse=flag=0;

            while(1)
            {
                n=sum;
                reverse=0;
                while(n!=0)
                {
                    remainder=n%10;
                    n=n/10;
                    b=reverse;
                    reverse=b*10+remainder;
                }
                if(sum==reverse&&flag!=0)
                {
                    printf("%d %lu\n",flag,reverse);
                    break;
                }
                else
                {
                    sum=sum+reverse;
                    flag++;
                }
            }
        }
    }
    return 0;
}

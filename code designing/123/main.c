#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    while(scanf("%d",&x)!= EOF)
    {
        long long int a[10000];
        int i;

        for(i=0; i<x; i++)
        {
            scanf("%d",&a[i]);
            long long int q=a[i],r=0,n=0;
            while(1)
            {
                a[i]=q;
                while(q!=0)
                {
                    r=r*10+q%10;
                    q=q/10;

                }

                if(r==a[i]&&n!=0)
                {
                    printf("%lld %lld\n",n,r);
                    break;
                }
                else
                {
                    q=r+a[i];
                    r=0;
                    n++;
                }
            }
        }
    }

    return 0;
}

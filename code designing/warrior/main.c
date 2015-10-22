#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a,b,c,d;
    while(scanf("%lld %lld", &a, &b) != EOF)
    {

        if(a>b)
        {
            c=a-b;
            printf("%lld\n",c);
        }
        else
        {
            d=b-a;
            printf("%lld\n",d);
        }




    }
    return 0;
}

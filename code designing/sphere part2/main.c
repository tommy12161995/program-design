#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a,b;
    while(scanf("%lld",&a)!=EOF)
    {
        if(a<=0)
            break;
        else if(a==1)
            printf("0%%\n");

        else
         printf("%lld%%\n",a*25);
    }
    return 0;
}

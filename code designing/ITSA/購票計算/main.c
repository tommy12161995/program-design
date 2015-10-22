#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int flag_10=0,flag_5=0;
        while(n>=10)
        {
            flag_10++;
            n-=10;
        }
        while(n>=5)
        {
            flag_5++;
            n-=5;
        }
        printf("NT10=%d\n",flag_10);
        printf("NT5=%d\n",flag_5);
        printf("NT1=%d\n",n);
    }
    return 0;
}

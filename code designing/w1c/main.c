#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,q;
    while(scanf("%d %d",&p,&q) != EOF)
    {
        if(q == 0)
        break;
        int a[100000] = {0},i,b;
        for(i = 1;i <= q;i++)
        {
            p=p*10%q;
            if(a[p] == 0)
            a[p]=i;
            else
            {
                b=i-a[p];
                break;
            }
        }
        printf("%d\n",b);
    }
    return 0;
}

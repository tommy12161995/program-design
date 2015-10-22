#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m;
    while(scanf("%f",&m)!=EOF)
    {
        m*=100;
        int c=(int)m/23.8;
        float d=m/23.8;
        if(c == d)
            printf("%d\n",c);
        else
            printf("%d\n",c+1);
    }
    return 0;
}

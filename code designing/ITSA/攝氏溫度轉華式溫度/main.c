#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    while(scanf("%f",&a)!=EOF)
    {
        float b;
        b=a*9/5+32;
        printf("%.1f\n",b);
    }
    return 0;
}

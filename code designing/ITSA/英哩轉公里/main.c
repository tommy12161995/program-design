#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    while(scanf("%f",&a)!=EOF)
    {
        printf("%.1f\n",a*1.6);
    }
    return 0;
}

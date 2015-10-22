#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    while(scanf("%f",&a)!=EOF)
    {
        float area;
        area=a*a+0.01;
        printf("%.1f\n",area);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    while(scanf("%f %f %f",&a,&b,&c)!=EOF)
    {
        float area;
        area=(a+b)*c/2;
        printf("Trapezoid area:%.1f\n",area);
    }
    return 0;
}

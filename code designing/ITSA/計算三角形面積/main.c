#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    while(scanf("%f %f",&a,&b)!=EOF)
    {
        float area;
        area=(a*b)/2;
        printf("%.1f\n",area);
    }
    return 0;
}

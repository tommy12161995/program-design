#include <stdio.h>
#include <stdlib.h>
int main()
{
    float a,b;
    while(scanf("%f",&a)!=EOF){
        b=a*1.6;
        printf("%.1f\n",b);
    }
    return 0;
}

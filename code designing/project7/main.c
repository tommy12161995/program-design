#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ADD(a,b) ((a)+(b))
#define SUBTRACT(a,b) ((a)>(b)?(a)-(b):(b)-(a))
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d比較大\n",MAX(a,b));
        printf("相加為%d\n",ADD(a,b));
        printf("相減為%d\n",SUBTRACT(a,b));
        printf("\n");

    }

    return 0;
}

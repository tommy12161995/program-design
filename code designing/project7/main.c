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
        printf("%d����j\n",MAX(a,b));
        printf("�ۥ[��%d\n",ADD(a,b));
        printf("�۴%d\n",SUBTRACT(a,b));
        printf("\n");

    }

    return 0;
}

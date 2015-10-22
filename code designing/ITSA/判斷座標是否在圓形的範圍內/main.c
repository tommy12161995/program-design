#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int len=a*a+b*b;
        if(len<=10000)
            printf("inside\n");
        else
            printf("outside\n");
    }
    return 0;
}

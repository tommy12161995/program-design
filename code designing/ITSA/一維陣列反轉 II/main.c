#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input[6]= {0};
    while(scanf("%d",&input[0])!=EOF)
    {
        for(int i=1; i<6; i++)
            scanf("%d",&input[i]);
        for(int i=5;i>=1;i--)
            printf("%d ",input[i]);
        printf("%d\n",input[0]);
    }

    return 0;
}

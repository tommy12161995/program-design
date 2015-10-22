#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input[6];
    while(scanf("%d",&input[0])!=EOF)
    {
        int sum=input[0]*input[0]*input[0];
        for(int i=1;i<6;i++)
        {
            scanf("%d",&input[i]);
            sum+=input[i]*input[i]*input[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}

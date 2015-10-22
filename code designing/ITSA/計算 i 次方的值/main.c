#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    while(scanf("%d",&i)!=EOF)
    {
        int sum=2;
        if(i>31)
            printf("Value of more than 31\n");
        else
        {
            for(int j=1; j<i; j++)
                sum*=2;
            printf("%d\n",sum);
        }



    }
    return 0;
}

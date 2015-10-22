#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,door_num;
    while(scanf("%d",&n)!=EOF)
    {
        int i,door[n];
        for(i=0; i<n; i++)
        {
            door[i]=0;
        }
        while(1)
        {
            scanf("%d",&door_num);
            if(door_num==-1)
            {
                break;
            }
            while(door[door_num]>=3)
            {
                door_num=door_num+1;
                if(door_num==n)
                {
                    door_num=0;
                }
            }
            door[door_num]=door[door_num]+1;
        }
        i=0;
        printf("%d",i);
        for(i=1; i<n; i++)
        {
            printf(" %d",i);
        }
        printf("\n");
        i=0;
        printf("%d",door[i]);
        for(i=1; i<n; i++)
        {
            printf(" %d",door[i]);
        }
        printf("\n");
    }

    return 0;
}

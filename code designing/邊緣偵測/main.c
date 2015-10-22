#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int width,length;
            scanf("%d %d",&width,&length);
            int array[width][length];
            for(int i=0;i<width;i++)
                for(int j=0;j<length;j++)
                    scanf("%d",&array[i][j]);
            for(int i=0;i<width;i++)
            {
                for(int j=0;j<length;j++)
                {
                    if(array[i][j]==0)
                        printf("_ ");
                    else if(array[i][j]==1)
                    {
                        if(array[i+1][j]==1&&array[i-1][j]==1&&array[i][j+1]==1&&array[i][j-1]==1)
                            printf("_ ");
                        else
                            printf("0 ");
                    }
                }
                printf("\n");
            }
            printf("\n");

        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int row,col;
            scanf("%d %d",&row,&col);
            int a[row][col],b[row][col];
            for(int i=0; i<row; i++)
                for(int j=0; j<col; j++)
                    scanf("%d",&a[i][j]);
            for(int i=0; i<row; i++)
                for(int j=0; j<col; j++)
                    scanf("%d",&b[i][j]);
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    if(j == col-1)
                        printf("%d\n",a[i][j]*b[i][j]);
                    else
                        printf("%d ",a[i][j]*b[i][j]);
                }

            }

        }
    }
    return 0;
}

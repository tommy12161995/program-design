#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A[3][3],i,j,win=0;
    while(scanf("%d %d %d",&A[0][0],&A[0][1],&A[0][2])!=EOF)
    {
        win=4;
        for(i=1; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                scanf("%d",&A[i][j]);
            }
        }
        if(A[0][0]==A[0][1]&&A[0][0]==A[0][2]) printf("True\n");
        else if(A[1][0]==A[1][1]&&A[1][0]==A[1][2]) printf("True\n");
        else if(A[2][0]==A[2][1]&&A[2][0]==A[2][2]) printf("True\n");
        else if(A[0][0]==A[1][0]&&A[0][0]==A[2][0]) printf("True\n");
        else if(A[0][1]==A[1][1]&&A[0][1]==A[2][1]) printf("True\n");
        else if(A[0][2]==A[1][2]&&A[0][2]==A[2][2]) printf("True\n");
        else if(A[0][0]==A[1][1]&&A[0][0]==A[2][2]) printf("True\n");
        else if(A[0][2]==A[1][1]&&A[0][2]==A[2][0]) printf("True\n");
        else printf("False\n");
    }
    return 0;
}

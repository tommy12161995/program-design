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
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                switch(A[i][j])
                {
                case 0:
                    printf("*");
                    break;
                case 1:
                    printf("Y");
                    break;
                case 2:
                    printf("X");
                    break;
                }
            }
            printf("\n");
        }
        if(A[0][0]==A[0][1]&&A[0][0]==A[0][2]) win=A[0][0];
        if(A[1][0]==A[1][1]&&A[1][0]==A[1][2]) win=A[1][0];
        if(A[2][0]==A[2][1]&&A[2][0]==A[2][2]) win=A[2][0];
        if(A[0][0]==A[1][0]&&A[0][0]==A[2][0]) win=A[0][0];
        if(A[0][1]==A[1][1]&&A[0][1]==A[2][1]) win=A[0][1];
        if(A[0][2]==A[1][2]&&A[0][2]==A[2][2]) win=A[0][2];
        if(A[0][0]==A[1][1]&&A[0][0]==A[2][2]) win=A[0][0];
        if(A[0][2]==A[1][1]&&A[0][2]==A[2][0]) win=A[0][2];
        if(win==1) printf("Y bingle\n");
        else if(win==2) printf("X bingle\n");
        else printf("Tie\n");
    }
    return 0;
}

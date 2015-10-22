#include <stdio.h>
#include <stdlib.h>
int main()
{
    int file_case,i,j,array[22][22],n,m,l,x,y,k;
    while(scanf("%d",&file_case)!=EOF){
        for(i=0;i<file_case;i++){
            scanf("%d %d %d",&n,&m,&l);
            memset(array,0,sizeof(array));
            for(j=0;j<l;j++){
                scanf("%d %d",&x,&y);
                array[x][y]=1;
                array[x-1][y]=1;
                array[x+1][y]=1;
                array[x][y+1]=1;
                array[x][y-1]=1;
            }
            int flag=1;
            for(j=1;j<=n;j++)
                for(k=1;k<=m;k++)
            {
                if(array[j][k]==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                printf("N\n");
            else
                printf("Y\n");

        }
    }
    return 0;
}

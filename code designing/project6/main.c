#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void queen(int n,int check_map[][n],int real_map[][n],int x);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int real_map[n][n],check_map[n][n],sum=0,x=1;
        memset(check_map,0,sizeof(check_map));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&real_map[i][j]);

        queen(n,check_map,real_map,x);

    }


    return 0;
}
void queen(int n,int check_map[][n],int real_map[][n],int x)
{
    int sum=0,flag=0,max=0;
    if(x<n)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(check_map[i][j]==0)
                {
                    check_map[i][j]=-1;
                    for(int k=1; k<n; k++)
                    {
                        check_map[i+k][j]++;
                        check_map[i][j+k]++;
                        check_map[i+k][j+k]++;
                        check_map[i+k][j-k]++;
                        check_map[i-k][j+k]++;
                        check_map[i-k][j-k]++;
                    }
                    //queen(n,check_map[n][n],real_map[n][n],x+1);
                }
            }
    }
    /*else if(x == n)
    {

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d ",check_map[i][j]);
            printf("\n");
        }

        /*for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(check_map[i][j]==-1)
                {
                    sum+=real_map[i][j];
                    flag++;
                }

            }
        if(flag == n&&sum>max)
            return max;
        else
            return -1;
        if(flag == n)
        {
            find_max(sum);
            find_min(sum);
        }
    }*/
}


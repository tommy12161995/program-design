#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        int i,j,input[100][100]={0},row[100]= {0},column[100]= {0},sum1,sum2,flag1=0,flag2=0,a,b;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&input[i][j]);
            }
        }
        for(i=0; i<n; i++)
        {
            sum1=0;
            sum2=0;
            for(j=0; j<n; j++)
            {
                sum1+=input[i][j];
                sum2+=input[j][i];
            }
            if(sum1%2!=0)
            {
                row[i]++;
                flag1++;
            }
            if(sum2%2!=0)
            {
                column[i]++;
                flag2++;
            }

        }
        if(flag1==0&&flag2==0)
        printf("OK\n");
        else if(flag1==1&&flag2==1)
        {
            for(i=0;i<n;i++)
            {
                if(row[i]==0&&column[i]==0)
                    continue;
                else if(row[i]!=0||column[i]!=0)
                {
                    if(row[i]!=0)
                        a=i+1;
                    else if(column[i]!=0)
                        b=i+1;
                }
            }
            printf("Change bit (%d,%d)\n",a,b);
        }
        else
            printf("Corrupt\n");
    }

    return 0;
}

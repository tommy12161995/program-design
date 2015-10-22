#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,s;
    while(scanf("%d",&n)!=EOF)
    {
        int a[3001]= {0},b[3001]= {0};
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(i!=0)
            {
                s=abs(a[i]-a[i-1]);
                b[s]++;
            }

        }
        for(i=1; i<n; i++)
        {
            if(b[i]==1&&i!=n-1)
                continue;
            else if(b[i]!=1)
            {
                printf("Not jolly\n");
                break;
            }
            else if(b[n-1]==1)
                printf("Jolly\n");
        }
        if(n==1)
            printf("Jolly\n");
    }

    return 0;
}

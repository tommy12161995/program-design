#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n) !=EOF)
    {
        int i,a[3001];
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int x=0,b[3000]= {0};
        for(i=0; i<n-1; i++)
        {
            x=abs(a[i]-a[i+1]);
            b[x]++;
        }
        for(i=1; i<n; i++)
        {
            if(b[i]!=1)
            {
                printf("Not jolly\n");
                break;
            }
            else if(i==n-1&&b[i]==1)

                printf("Jolly\n");

        }

    }
    return 0;
}

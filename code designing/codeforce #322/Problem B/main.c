#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int builds[n];
        for(int i=0; i<n; i++)
            scanf("%d",&builds[i]);
        int num[n],max=0;
        for(int i=n-1; i>=0; i--)
        {
            if(builds[i]>max)
            {
                max=builds[i];
                num[i]=max-builds[i];
            }
            else
                num[i]=max-builds[i]+1;

        }
        for(int i=0; i<n; i++)
            printf("%d ",num[i]);
        printf("\n");
    }
    return 0;
}

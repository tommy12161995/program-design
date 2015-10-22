#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        int edge[n];
        for(int i=0; i<n; i++)
            scanf("%d",&edge[i]);
        int flag=0;
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(edge[i]+edge[j]>edge[k]&&edge[i]+edge[k]>edge[j]&&edge[k]+edge[j]>edge[i])
                        flag++;
        printf("%d\n",flag);
    }
    return 0;
}

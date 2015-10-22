#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
          break;
        long long int map[n+1][n+1];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%lld",&map[i][j]);
        long long int opt[n+1][n+1];
        memset(opt,0,sizeof(opt));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(opt[i-1][j]>=opt[i][j-1])
                    opt[i][j]=opt[i-1][j]+map[i][j];
                else
                    opt[i][j]=opt[i][j-1]+map[i][j];
            }
            printf("%lld\n",opt[n][n]);
    }
    return 0;
}

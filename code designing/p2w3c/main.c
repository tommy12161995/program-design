#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int spy;
            scanf("%d",&spy);
            int mark[10000]={0};
            int leader[spy],s=0;
            for(int i=1;i<spy;i++)
                scanf("%d",&leader[i]);
            for(int i=spy-1;i>0;i--)
            {
                if(mark[i]==0)
                    mark[leader[i]]=1;
                else
                    s++;
            }
            s+=mark[0];
            printf("%d\n",s);
        }
    }
    return 0;
}

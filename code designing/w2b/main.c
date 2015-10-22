#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i,a[2],b[7];
        for(i=6;i>=0;i--)
        {
            b[i]=m%10;
            m/=10;
        }
        a[0]=n/10;
        a[1]=n%10;
        int flag=0;
        for(i=0;i<6;i++)
        {
            if(a[0]==b[i]&&a[1]==b[i+1])
               flag++;
        }
        printf("%d\n",flag);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int min(int a , int b);
int main()
{
    int n;
    while(scanf("%d" , &n) != EOF)
    {
        if(n == 0)
            break;
        int a[n],b[n];
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i],&b[i]);
        int t1=abs(1000-a[0]),t2=abs(1000-b[0]);
        int x1,y1,x2,y2;
        for(int i=1;i<n;i++)
            {
                x1=t1+abs(a[i]-a[i-1]);
                y1=t2+abs(a[i]-b[i-1]);
                x2=t1+abs(b[i]-a[i-1]);
                y2=t2+abs(b[i]-b[i-1]);
                t1=min(x1,y1);
                t2=min(x2,y2);

            }
            if(t1>=t2)
                printf("%d\n",t2);
            else
                printf("%d\n",t1);

    }
    return 0;
}
int min(int a , int b)
{
    if(a >= b)
        return b;
    else
        return a;
}

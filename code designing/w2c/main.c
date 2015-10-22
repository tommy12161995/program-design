#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            long long int x,y,N,c;
            scanf("%lld %lld %lld",&x,&y,&N);
            long long int a[10001]= {0},number[10001]= {0},i,b=0;
            c=x;
            for(i=0; i<y; i++)
            {
                if(i==0)
                {
                    x=x%N;
                    a[x]=i+1;
                    number[i+1]=x;
                }
                else
                {
                    x=x*c%N;
                    if(a[x]==0)
                    {
                        a[x]=i+1;
                        number[i+1]=x;
                    }
                    else
                    {
                        b=i-a[x];
                        break;
                    }
                }
            }
            if(b != 0)
                y=y%b;
            if(y == 0)
                printf("%lld\n",number[b]);
            else
                printf("%lld\n",number[y]);


        }
    }
    return 0;
}

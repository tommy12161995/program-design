#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF) {
        long long int x,y,N,c;
        while(n--) {
            scanf("%lld %lld %lld",&x,&y,&N);
            long long int a[10002]= {0},number[10002]= {0},i,b=0;
            c=x;
            for(i=0; i<y; i++) {
                if(i==0) {
                    x=x%N;
                    a[x]=i+1;
                    number[i+1]=x;
                } else {
                    x=x*c%N;
                    if(a[x]==0) {
                        a[x]=i+1;
                        number[i+1]=x;
                    } else {
                        b = i + 1 - a[x];
                        long long int pre_cycle = a[x] - 1;
                        b = (y - pre_cycle) % (i + 1 - a[x]) + pre_cycle;
                        number[0] = number[1];
                        break;
                    }
                }
            }
            if(y == i) {
                printf("%lld\n", x);
            } else {
                printf("%lld\n",number[b]);
            }
        }
    }
    return 0;
}

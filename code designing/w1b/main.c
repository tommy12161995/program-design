#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int D,Q_1,Q_2,R_1,R_2;
            scanf("%d %d %d %d",&Q_1,&R_1,&Q_2,&R_2);
            int a,b,c;
            a=Q_1-R_1;
            b=Q_2-R_2;
            while(1)
            {
                if(a%b==0||b%a==0)
                {
                    if(a>=b)
                        c=b;
                    else
                        c=a;
                    break;
                }
                else if(a>b)
                    a=a%b;
                else if(b>a)
                    b=b%a;
            }
            int i;
            for(i=1; i<=c; i++)
            {
                if(c==i)
                    printf("%d\n",c);
                else if(c%i==0)
                    printf("%d ",i);
            }
        }

    }

    return 0;
}

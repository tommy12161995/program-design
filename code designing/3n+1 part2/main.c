#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d=1,f=0;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        f=0;
        printf("%d %d ",a,b);
            int temp;
        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        for(; a<=b; a++)
        {
            c=a;
            while(1)
            {

            if(c%2==0)
                c=c/2;
            else if(c==1)
                break;
            else
                c=3*c+1;
                d++;
            }
            if(f<d)
                f=d;
            d=1;

        }

       printf("%d\n",f);
    }
    return 0;
}

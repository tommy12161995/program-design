#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int c;
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
        printf("%d\n",c);
    }


    return 0;
}

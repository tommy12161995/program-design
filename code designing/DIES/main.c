#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6],b[6],i,c;
    char n[10];


    while(scanf("%d",&c)!=EOF&& c!=0)
    {
        a[0]=1;
        a[1]=2;
        a[2]=3;
        a[3]=4;
        a[4]=5;
        a[5]=6;
        int k;
        for(k = 0; k < 6; k++)
        {
            b[k] = a[k];
        }

        for(i=1; i<=c; i++)
        {
            scanf("%s",n);
            if(n[0]=='n')
            {
                a[0]=b[4];
                a[4]=b[5];
                a[5]=b[1];
                a[1]=b[0];

            }
            else if(n[0]=='s')
            {
                a[0]=b[1];
                a[1]=b[5];
                a[5]=b[4];
                a[4]=b[0];

            }
            else if(n[0]=='w')
            {
                a[0]=b[3];
                a[3]=b[5];
                a[5]=b[2];
                a[2]=b[0];

            }
            else if(n[0]=='e')
            {
                a[0]=b[2];
                a[2]=b[5];
                a[5]=b[3];
                a[3]=b[0];

            }
            else
                break;


        }
        printf("%d\n",a[0]);
    }

    return 0;
}

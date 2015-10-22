#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,temp;
    char direction[10];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int a[6];
        a[0]=1;
        a[1]=2;
        a[2]=3;
        a[3]=4;
        a[4]=5;
        a[5]=6;
        while(n--)
        {
            scanf("%s",&direction);
            if(direction[0]=='n')
            {
                temp=a[0];
                a[0]=a[4];
                a[4]=a[5];
                a[5]=a[1];
                a[1]=temp;
            }
            else if(direction[0]=='s')
            {
                temp=a[0];
                a[0]=a[1];
                a[1]=a[5];
                a[5]=a[4];
                a[4]=temp;
            }
            else if(direction[0]=='e')
            {
                temp=a[0];
                a[0]=a[2];
                a[2]=a[5];
                a[5]=a[3];
                a[3]=temp;
            }
            else if(direction[0]=='w')
            {
                temp=a[0];
                a[0]=a[3];
                a[3]=a[5];
                a[5]=a[2];
                a[2]=temp;
            }
            else
                break;
        }
        printf("%d\n",a[0]);

    }
    return 0;
}

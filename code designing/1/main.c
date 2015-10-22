#include <stdio.h>
#include <stdlib.h>

int main()
{
    int son,mom,leave,real;
    while(EOF!=scanf("%d",&son))
    {
        scanf("%d",&mom);
        if(mom==0)
            break;
        int num[100000]={0};
        int i,a=2,k;
        leave=son*10%mom;
        num[leave]=1;
        for(i=2; i<100000; i++)
        {
            leave=leave*10%mom;
            int j;
            if(num[leave]==0)
            {
                num[leave]=a;
                a++;
            }
            else if(num[leave]!=0)
            {
                real=i-num[leave];
                break;
            }
        }
        printf("%d\n",real);


    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],b[100];
    int i,j,k,x,y,z,sum,temp=0;
    scanf("%d",&j);
    for(i=0; i<j; i++)
    {
        scanf("%d",&a[i]);

    }


    for(k=0; k<j; k++)
    {
             sum=0;
        for(i=k; i<j; i++)
        {
            sum=a[i]+sum;

            if(sum>temp)
            {
                temp=sum;
            }

        }
    }
    printf("%d",sum);



    return 0;
}

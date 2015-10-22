#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long int number;
    while(scanf("%lld",&number)!=EOF)
    {
        if(number==0)
            break;
        printf("%lld : ",number);
        int n=2,flag=0,a=0,i;

       for(i=2;i<=number;i++)
       {
           n=i;
           a=0;
           while(number%n==0)
           {
               number/=n;
               a++;
               if(a==1)
                flag++;
           }

       }
        printf("%d\n",flag);

    }
    return 0;
}

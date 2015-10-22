#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
            break;
        long long int input,output=0;
        while(n--)
        {
            scanf("%lld",&input);
            long long int decimal_number=0;
            int binary_number[32]= {0},i=0,j;
            while(input!=0)
            {
                binary_number[i]=input%10;
                input/=10;
                i++;
            }
            for(j=i-1; j>0; j--)
            {
                decimal_number=(decimal_number+binary_number[j])*2;
            }
            output+=decimal_number+binary_number[0];
            if(n == 0)
                printf("%lld\n",output);
        }
    }
    return 0;
}

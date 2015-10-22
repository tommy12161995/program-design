#include <stdio.h>
#include <stdlib.h>
#include<math.h>
reverse(int a)
{
    int remainder,b=0,c=0;
    while(a!=0)
    {
        remainder=a%10;
        a=a/10;
        b=c;
        c=b*10+remainder;
    }
    return c;
}

int main()
{
    int n;

    while(scanf("%d", &n)!=EOF)
    {
        long long int i,m, input, temp;
        long long int row[100000]= {0}, sum[100000]= {0};
        for(i=1; i<100000; i++)
        {
            if(i<10)
            {
                row[i] = row[i-1] + 1;
            }
            else if(10<=i && i<100)
            {
                row[i] = row[i-1] + 2;
            }
            else if(100<=i && i<1000)
            {
                row[i] = row[i-1] + 3;
            }
            else if(1000<=i && i<10000)
            {
                row[i] = row[i-1] + 4;
            }
            else if(10000<=i)
            {
                row[i] = row[i-1] + 5;
            }
        }

        for(i=1; i<100000; i++)
        {
            sum[i] = sum[i-1]+row[i];

        }
        for(m=0; m<n; m++)
        {
            scanf("%lld", &input);

            for(i=1; i<100000; i++)
            {
                if(sum[i-1]<input && input<=sum[i])
                {
                    input-=sum[i-1];
                    break;
                }
            }
            int j;
            for(j=1; j<=i; j++)
            {
                if(input<=0)
                    break;
                temp = input;

                if(j<10)
                {
                    input -= 1;
                }
                else if(10<=j && j<100)
                {
                    input -= 2;
                }
                else if(100<=j && j<1000)
                {
                    input -= 3;
                }
                else if(1000<=j && j<10000)
                {
                    input -= 4;
                }
                else if(10000<=j )
                {
                    input -= 5;
                }

            }

            int k;
            int e=1;
            j-=1;
            k=reverse(j);
            while(temp--)
            {

                e=k%10;
                k/=10;

            }
            printf("%d\n",e);


        }
    }
    return 0;
}

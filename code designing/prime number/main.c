#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[22];
    while(fgets(input,22,stdin)!=NULL)
{
        int len=0,i,sum=0,temp=0,n=0,flag=0;
        len=strlen(input);
        for(i=0; i<len-1; i++)
        {
            temp=input[i];
            if(65<=temp&&temp<=90)
                temp-=38;
            else if(97<=temp&&temp<=122)
                temp-=96;
            sum+=temp;
        }
        n=sum;
        for(i=2; i<sum; i++)
        {

            while(n%i==0)
            {
                n/=i;
                flag++;
            }
        }
        if(flag==0)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");


}
    return 0;
}

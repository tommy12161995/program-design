#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,n,k,factor[52],num,flag,len;
    char character[22]={0};
    while(scanf("%s",&character)!=EOF)
    {

        for(i=0; i<52; i++)
        {
            factor[i]=0;
        }


        len=strlen(character);
        for(j=0; j<len; j++)
        {
            if(character[j]>='a'&&character[j]<='z')
                factor[character[j]-'a']++;
            if(character[j]>='A'&&character[j]<='Z')
                factor[character[j]-'A'+26]++;
        }


        num=0;
        for(k=0; k<52; k++)
        {
            num=num+(k+1)*factor[k];

        }

        flag=0;
        {
            if(3<num)
            {
                for(n=2; n<num; n++)
                {
                    if(0==num%n)
                        flag=1;
                }
            }
        }

        if(0==flag)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");

    }
    return 0;
}

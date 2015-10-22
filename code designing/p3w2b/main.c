#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[2000];
    while(fgets(input,2000,stdin)!=NULL)
    {
        int len=0;
        len=strlen(input);
        int num[len];
        memset(num,0,sizeof(num));
        for(int i=0; i<len; i++)
        {
            if('1'<=input[i]&&input[i]<='9')
                num[i]=input[i]-'0';
        }



        for(int i=0; i<len; i++)
        {

            if(num[i]!=0)
            {
                for(int j=0; j<num[i]; j++)
                {
                    for(int k=i+1; k<len-1; k++)
                    {
                        if(num[k]==0)
                            printf("%c",input[k]);
                        else break;
                    }
                }
            }
        }
        printf("\n");

    }
    return 0;
}

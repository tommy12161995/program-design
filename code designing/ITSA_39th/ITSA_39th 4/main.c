#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[20000],tmp,add[20000];
    int n,i,len,a,j,k,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",input);
        for(i=0;i<strlen(input);i++)
        {
        memset(add,'\0',sizeof(add));
           if(input[i]=='a')
           {
               a=i+1;
               len=strlen(input);
               for(j=0;j<(strlen(input)-i-1)/2;j++)
               {
                   len--;
                   tmp=input[a];
                   input[a]=input[len];
                   input[len]=tmp;
                   a++;
               }
               continue;
           }
           if(input[i]=='b')
           {
               k=0;
               for(j=i+1;j<strlen(input);j++)
               {
                   add[k]=input[j];
                   k++;
               }
               strcat(input,add);
               continue;
           }
           if(input[i]=='c')
           {
            m=0;
            for(j=i+3;j<strlen(input);j++)
            {
              add[m]=input[j];
              m++;
            }
            input[i+1]='\0';
            strcat(input,add);
           }
        }
        printf("%s\n",input);
    }
    return 0;
}

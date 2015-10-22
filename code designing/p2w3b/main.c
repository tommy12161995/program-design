#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[10000];
    while(fgets(input,10000,stdin)!=NULL)
    {
        int num=strlen(input);
        for(int i=0;i<num;i++)
        {
            if(input[i]>='A'&&input[i]<='Z')
                input[i]=26-(input[i]-'A')+'a'-1;
            else if(input[i]>='a'&&input[i]<='z')
                input[i]=26-(input[i]-'a')+'A'-1;
            else if(input[i]>='0'&&input[i]<'9')
                input[i]+=1;
            else if(input[i]=='9')
                input[i]='0';
            printf("%c",input[i]);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF) {
        if(n==0)
            break;
        getchar();
        int len=0,number=0,i,sum=0;
        char input[102];
        fgets(input,102,stdin);
        len=strlen(input);
        number=(len-1)/n;
        while(n--)
        {
            for(i=sum + number - 1; i>=sum; i--)
                printf("%c",input[i]);

            sum+=number;
        }

        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        while(n--)
        {
            char input[300];
            fgets(input,300,stdin);
            int len=strlen(input);
            for(int i=len-2;i>=0;i--)
                printf("%c",input[i]);
            printf("\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    while(scanf("%d",&input)!=EOF)
        printf("%d %d %d\n",input,input*input,input*input*input);
    return 0;
}

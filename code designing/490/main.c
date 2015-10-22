#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=0,j=0,a[100]= {0},max=0,line=0;
    char input[102][102];
    memset(input, ' ', sizeof(input));
    while(fgets(input[line],102,stdin)!=NULL)
    {
        a[line]=strlen(input[line]);
        if(a[line]>max)
            max=a[line];
        line++;
    }

    for(i=0; i<max-1; i++)
    {
        for(j=line-1; j>=0; j--)
        {
            if(input[j][i] == '\n' || input[j][i] == '\0')
                printf(' ');
            else
                printf("%c",input[j][i]);
        }
        printf("\n");
    }

    return 0;
}

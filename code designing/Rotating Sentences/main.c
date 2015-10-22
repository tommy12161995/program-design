#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=0,j,a[100]= {0},max=0,line=0;
    char input[102][102]={' '};
    while(fgets(input[line],102,stdin)!=NULL)
    {
        a[line]=strlen(input[line]);
        if(i!=0&&a[line]>a[line-1])
            max=a[line];
            line++;
    }

    for(i=max-1;i>=0;i--)
    {
        for(j=line-1;j>=0;j--)
        {
            printf("%c",input[j][i]);
        }
        printf("\n");
    }





    return 0;
}

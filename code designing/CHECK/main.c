#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int len;
    int len_max = 0;
    int i,j,count=0;
    char set[102][102];
    memset(set, ' ', sizeof(set));
    while(fgets(set[count],102,stdin)!= NULL)
    {
        len=strlen(set[count]);
        if(set[count][len-1]=='\n')
        {
            set[count][len-1] = ' ';
            set[count][len] = ' ';
            len--;
        }
        if(len>len_max)
        {
            len_max = len;
        }
        count++;
    }
    for(i=0; i<len_max; i++)
    {
        for(j=count-1; j>=0; j--)
        {
            printf("%c",set[j][i]);
        }
        printf("\n");
    }
    return 0;

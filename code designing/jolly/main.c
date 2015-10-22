#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,line[3000],a,s[3000],b,digit,c,i;
    while(scanf("%d",&n)!=EOF)
    {
    for(i=0;i<n;i++)
    {
       scanf("%d",&line[i]);
    }
        for(a=0; a<3000; a++)
        {
            s[a]=0;
        }
        s[n]=3001;
        for(b=1; b<n; b++)
        {
            digit=line[b]-line[b-1];
            if(digit>=0)
                digit=digit;
            else
                digit=-digit;
            s[digit]++;
        }
        for(c=1; c<=n; c++)
        {
            if(s[c]==1)
                continue;
            else if(s[c]==3001)

                printf("Jolly\n");

            else
            {
                printf("Not jolly\n");
                break;
            }
        }
    }
    return 0;
}

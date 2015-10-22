#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,i,j,a[127],ah;
    char str[1000],word;
    while(scanf("%d",&n)!=EOF)
    {
        n++;
        for(i=0; i<127; i++)
        {
            a[i]=0;
        }
        while(n--)
        {
            for(i=0; i<1000; i++)
            {
                str[i]='\0';
            }
            gets(str);
            for(j=0; j<1000; j++)
            {
                ah=str[j];
                a[ah]++;
            }
            for(i=65; i<=90; i++)
            {
                a[i]=a[i]+a[i+32];
                a[i+32]=0;
            }
        }
            for(i=1000; i>0; i--)
            {
                for(j=65; j<=90; j++)
                {
                    if(a[j]==i)
                    {
                        word=j;
                        printf("%c %d\n",word,i);
                    }
                }
            }
    }
    return 0;


}

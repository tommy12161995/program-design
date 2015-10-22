#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,alphabet;

    char line[1000],word;
    while(EOF!=scanf("%d",&n))
    {
        int num[127]= {0};
        n++;
        while(n--)
        {
            for(i=0; i<1000; i++)
            {
                line[i]='\0';
            }
            fgets(line,9999,stdin);
            for(i=0; i<1000; i++)
            {
                alphabet=line[i];
                num[alphabet]++;
            }
            i=65;
            while(65<=i&&i<=90)
            {
                num[i]=num[i]+num[i+32];
                num[i+32]=0;
                i++;
            }
        }

        for(i=1000; i>0; i--)
        {
            for(j=65; j<=90; j++)
            {
                if(num[j]==i)
                {
                    word=j;
                    printf("%c %d\n",word,i);
                }
            }
        }
    }

    return 0;
}

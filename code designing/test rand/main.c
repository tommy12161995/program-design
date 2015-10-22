#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char num[14]= {'2','3','4','5','6','7','8','9','T','J','Q','K','A'},color[5]={'\6','\3','\4','\5'};
    int i,j,k;
    srand(time(NULL));
    for(i=1; i<=14; i++)
    {
            num[i]=rand()%13+1;
    }
    for(i=1;i<=5;i++)
    {
        color[k]=rand()%4+1;
    }
    for(j=1; j<=2; j++)
    {
        printf("%d %d\n",num[j],color[j]);
    }

    return 0;
}

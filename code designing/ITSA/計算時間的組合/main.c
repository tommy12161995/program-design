#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sec;
    while(scanf("%d",&sec)!=EOF)
    {
        int day=0,hr=0,min=0;
        day=sec/86400;
        sec=sec%86400;
        hr=sec/3600;
        sec=sec%3600;
        min=sec/60;
        sec=sec%60;
        printf("%d days\n",day);
        printf("%d hours\n",hr);
        printf("%d minutes\n",min);
        printf("%d seconds\n",sec);
    }
    return 0;
}

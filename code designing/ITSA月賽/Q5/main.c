#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int a,c,m,X,flag=2,cycle_length=0;
            scanf("%d %d %d %d",&a,&c,&m,&X);
            int cycle_check[m];
            memset(cycle_check,0,sizeof(cycle_check));
            cycle_check[X]++;
            while(1)
            {
                 X=(X*a+c)%m;
                 if(cycle_check[X]==0)
                    {
                        cycle_check[X]=flag;
                        flag++;
                    }
                 else if(cycle_check[X]!=0)
                 {
                     cycle_length=flag-cycle_check[X];
                     break;
                 }
            }
            printf("%d\n",cycle_length);
        }
    }
    return 0;
}

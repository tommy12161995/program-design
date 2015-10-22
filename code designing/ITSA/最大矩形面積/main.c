#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int input_1,i,j,a[50]={0},b[50]={0},length=0,width=0,area=0;
        scanf("%d",&input_1);
        for(i=0;i<input_1;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        for(i=0;i<input_1;i++)
        {
            for(j=i+1;j<input_1;j++)
            {
                length=abs(a[i]-a[j]);
                width=abs(b[i]-b[j]);
                if(area<length*width)
                  area=length*width;
            }
        }
        printf("%d\n",area);
        }

    }
    return 0;
}

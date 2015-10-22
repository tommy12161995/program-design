#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int num[n];
        for(int i=0; i<n; i++)
            scanf("%d",&num[i]);
        int max=0,length=1;
        for(int i=1; i<n; i++)
        {
           if(i == n-1)
           {
               if(num[i]>=num[i-1]&&max<length)
                max=length+1;
           }
           if(num[i]>=num[i-1])
              length++;
           else
           {
               if(max<length)
                max=length;
               length=1;
           }

        }
        if(n == 1)
            max=1;
         printf("%d\n",max);

    }
    return 0;
}

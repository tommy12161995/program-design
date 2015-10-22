#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n == 0)
            break;
        int input,set[2500],right=0,left=0,number=0;
        memset(set,-1,sizeof(set));
        for(int i=0; i<n; i++)
        {
             scanf("%d",&input);
            if(set[input] == -1)
                set[input] = i;
            else
            {
                if((right - left) <(i-set[input]))
                {
                    right=i;
                    left=set[input];
                    number=input;
                }
            }
        }
        if(right !=0)
            printf("(%d,%d):%d\n",left,right,number);
        else
            printf("No solution\n");

    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int witch_desire,alligator_legs_num,bat_eyes_num,cat_skulls_num,alligator_legs_level,bat_eyes_level,cat_skulls_level;
            scanf("%d %d %d %d %d %d %d",&witch_desire,&alligator_legs_num,&bat_eyes_num,&cat_skulls_num,&alligator_legs_level,&bat_eyes_level,&cat_skulls_level);
            int flag=0;
               for(int i=0;i<=alligator_legs_num;i++)
                for(int j=0;j<=bat_eyes_num;j++)
                  for(int k=0;k<=cat_skulls_num;k++)
                    if(i*alligator_legs_level+j*bat_eyes_level+k*cat_skulls_level==witch_desire)
                       {
                           flag=1;
                           break;
                       }

            if(flag == 1)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}

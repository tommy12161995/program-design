#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        int cell[10000]= {0},i;
        for(i=0; i<n; i++)
            scanf("%d",&cell[i]);
        while(m--)
        {
            int set,direction,after_set,flag=0,dir_cnt[2][10000]= {0};
            scanf("%d %d",&set,&direction);
            while(1)
            {
                after_set=set+cell[set]*direction;
                flag++;
                if(after_set<0)
                {
                    printf("Backward\n");
                    break;
                }
                if(after_set>n-1)
                {
                    printf("Forward\n");
                    break;
                }
                if(dir_cnt[0][after_set]!=0&&after_set>set)
                {
                    printf("Cycle %d\n",flag-dir_cnt[0][after_set]);
                    break;
                }

                if(dir_cnt[1][after_set]!=0&&after_set<set)
                {
                    printf("Cycle %d\n",flag-dir_cnt[1][after_set]);
                    break;
                }
                if(after_set>set&&dir_cnt[0][after_set]==0)
                {
                    dir_cnt[0][after_set]=flag;
                    direction=1;
                }
                else if(after_set<set&&dir_cnt[1][after_set]==0)
                {
                    dir_cnt[1][after_set]=flag;
                    direction=-1;
                }
                set=after_set;

            }
        }
    }
    return 0;
}

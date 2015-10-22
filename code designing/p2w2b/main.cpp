#include <stdio.h>
#include <stdlib.h>
#include <queue>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int job,machine;
            scanf("%d %d",&job,&machine);
            std::priority_queue<int> input;
            for(int i=0;i<machine;i++)
                input.push(0);
            int temp_job;
            for(int i=0;i<job;i++)
            {
                scanf("%d",&temp_job);
                temp_job*=(-1);
                temp_job+=input.top();
                input.pop();
                input.push(temp_job);
            }
             int max_time;
             while(!input.empty())
             {
                 max_time=input.top();
                 input.pop();
             }
             printf("%d\n",max_time*(-1));

        }
    }
    return 0;
}

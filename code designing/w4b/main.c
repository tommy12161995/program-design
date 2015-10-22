#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            int N,M;
            scanf("%d %d",&N,&M);
            int item[10000]={0},student[10000]={0},i;
            for(i=0;i<N;i++)
                scanf("%d",&item[i]);
            for(i=0;i<M;i++)
                scanf("%d",&student[i]);
            qsort(item,N,sizeof(int),cmp);
            qsort(student,M,sizeof(int),cmp);
            int flag=0,value=0;
            for(i=0;i<M;i++)
            {
                if(student[i]>=item[flag])
                {
                    value+=student[i];
                    flag++;
                }
                if(flag == N)
                {
                    printf("%d\n",value);
                    break;
                }
                if(i == M-1)
                {
                    printf("-1\n");
                    break;
                }
            }
        }
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

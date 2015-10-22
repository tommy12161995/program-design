#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

int main()
{
    int people;
    while(scanf("%d",&people)!=EOF)
    {
        if(people == 0)
            break;
        int enemy[10000]={0},soldier[10000]={0},i;
        for(i=0;i<people;i++)
            scanf("%d",&enemy[i]);
        for(i=0;i<people;i++)
            scanf("%d",&soldier[i]);
        qsort(enemy,people,sizeof(int),cmp);
        qsort(soldier,people,sizeof(int),cmp);
        int flag=0;
        for(i=0;i<people;i++)
        {
            if(soldier[i]>enemy[flag])
            flag++;
        }
        printf("%d\n",flag);
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int left;
    int right;
} part;
int cmp(const void *a,const void *b);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        getchar();
        while(n--)
        {
            char time_length[100]={'\0'};
            part data[210];
            int i=0;
            while(1)
            {
                if(time_length[0]=='\n'||fgets(time_length,10,stdin)==NULL)
                    break;
                sscanf(time_length,"%d %d",&data[i].left,&data[i].right);
                int temp;
                if(data[i].left>data[i].right)
                {
                    temp=data[i].left;
                    data[i].left=data[i].right;
                    data[i].right=temp;
                }
                i++;
            }
            qsort(data,i,sizeof(part),cmp);
            int right_max=0,flag=1,temp=0;
            for(int j=0;j<i;j++)
            {
                if(data[j].left==0&&data[j].right>right_max)
                    right_max=data[j].right;
                else if(data[j].left<=right_max+1&&data[j].right>temp)
                    temp=data[j].right;
                else if(data[j].left>right_max)
                {
                    right_max=temp;
                    flag++;
                    j--;
                }
               if(temp==199)
                    {
                        flag++;
                        break;
                    }

            }
            printf("%d\n",flag);

        }
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
    return ((part*)a)->left-((part*)b)->left;
}

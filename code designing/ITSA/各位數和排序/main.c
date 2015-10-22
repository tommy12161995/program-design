#include <stdio.h>
#include <stdlib.h>
int cmp_sum(const void *a,const void *b);
typedef struct
{
    int num;
    int sum;
}part;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        part a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].num);
            int b=a[i].num;
            a[i].sum=0;
            while(b)
            {
                a[i].sum+=b%10;
                b/=10;
            }
        }
    qsort(a,n,sizeof(part),cmp_sum);
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i].num);
    printf("%d\n",a[n-1].num);
    }
    return 0;
}
int cmp_sum(const void *a,const void *b)
{
    if(((part *)a)->sum-((part *)b)->sum!=0)
       return ((part *)a)->sum-((part *)b)->sum;
    else
       return ((part *)a)->num-((part *)b)->num;
}

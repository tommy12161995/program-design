#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int length;
    int width;
} part;
int cmp(const void *a,const void *b);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int number;
            scanf("%d",&number);
            part brick[2*number];
            for(int i=0; i<number; i++)
                scanf("%d %d",&brick[i].length,&brick[i].width);
            for(int i=number; i<2*number; i++)
            {
                brick[i].length=brick[i-number].width;
                brick[i].width=brick[i-number].length;
            }
            qsort(brick,2*number,sizeof(part),cmp);
            int max=brick[0].width,sum=0;
            for(int i=0;i<2*number;i++)
               {
                   if(brick[i].length==brick[i+1].length)
                      {
                          if(brick[i+1].width>max)
                             max=brick[i+1].width;
                      }
                    else if(brick[i].length!=brick[i+1].length)
                       {
                           sum+=max;
                           max=brick[i+1].width;
                       }
               }
            printf("%d\n",sum);

        }
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    return ((part *)a)->length - ((part *)b)->length;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
typedef struct
{
    int row;
    int value[10][10];
    int map[10][10];
} part;
void queens(part data,int num);
int max,min;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int num;
            scanf("%d",&num);
            part data;
            memset(data.value,0,sizeof(data.value));
            for(int i=0; i<num; i++)
                for(int j=0; j<num; j++)
                    scanf("%d",&data.value[i][j]);
            data.row=0;
            memset(data.map,0,sizeof(data.map));
            max=0;
            min=-1;
            queens(data,num);
            printf("%d %d\n",max,min);
            max=0;
            min=-1;
        }
    }
    return 0;
}
void queens(part data,int num)
{
    part t;
    int sum=0;
    if(data.row == num)
    {
        for(int i=0; i<num; i++)
        {
            for(int j=0; j<num; j++)
            {
                if(data.map[i][j] == -1)
                    sum+=data.value[i][j];
            }
        }
        max=MAX(sum,max);
        if(min == -1)
            min=sum;
        else
            min=MIN(sum,min);
    }
    else
    {
        for(int i=0; i<num; i++)
        {
            if(data.map[data.row][i] == 0)
            {
                t=data;
                t.map[t.row][i]=-1;
                for(int j=t.row+1; j<num; j++)
                {
                    t.map[j][i]=1;
                }
                for(int j=1; j<num; j++)
                {
                    if( (t.row+j)<num && (i-j)>=0 )
                        t.map[t.row+j][i-j]=1;
                    if( (t.row+j)<num && (i+j)<num )
                        t.map[t.row+j][i+j]=1;
                }
                t.row++;
                queens(t,num);
            }
        }
    }

}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int room[300]={0},man[300]={0},staroom[300]= {0},count[300]={0};//man is sec input staroom is sec output count is last output
    int n,i,length,m,c,b;
    scanf("%d",&n);//n=room

    for(i=0; i<=n; i++)
    {
        scanf("%d",&man[i]);
        if(man[i]==-1)
            break;
    }

    for(i=0; i<n; i++) //output 1st line

    {
        room[i]=i+1;
        if(room[i]<10);
        {
            printf("00%d ",room[i]);
        }
        if(10<=room[i]&&room[i]<100);
        {
            printf("0%d ",room[i]);
        }
        if(100<=room[i])
        {
            printf("%d ",room[i]);
        }

    }
    printf("\n");


    length=(sizeof(man)/sizeof(man[0]))-1;//choice room amount-1(-1)
    m=0;
    for(i=0; i<length; i++)
    {
        while(1)
        {
            if(staroom[man[i]-1]==0)
            {
                staroom[man[i]-1]=1;
                count[m]=man[i];
                m++;
                break;
            }
            for(b=0; b<n-man[i]; b++)
            {
                if(staroom[man[i]+b]==0)
                {
                    staroom[man[i]+b]=1;
                    count[m]=man[i]+b+1;
                    m++;
                    break;
                }
            }
            if(count[m-1]=man[i]+b+1)
            {
                break;
            }

            for(c=0; c<n; c++)
            {
                if(staroom[c]==0)
                {
                    staroom[c]=1;
                    count[m]=c+1;
                    m++;
                    break;
                }
            }
            break;
        }
    }
    for(i=0; i<n; i++)
    {
        if(i!=0)
        {
            printf("  ");
        }

        printf(" %d",staroom[i]);
    }
    printf("\n");
    for(m=0; m<length; m++)
    {
        if(m!=0)
        {
            printf(" ");
        }
        printf("%d",count[m]);
    }

    return 0;
}

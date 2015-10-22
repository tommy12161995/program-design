#include <stdio.h>
#include <stdlib.h>

int main()
{
    int time;
    while(EOF!=scanf("%d",&time))
    {
        while(time>0)
        {
            int Q1=0,Q2=0,R1=0,R2=0,A1=0,A2=0;
            scanf("%d %d %d %d",&Q1,&R1,&Q2,&R2);
            if(Q1>R1&&Q2>R2)
            {
                A1=Q1-R1;
                A2=Q2-R2;
                int temp=0,B1=0;

                if(A1>=A2)
                {
                    B1=A1%A2;
                    while(B1!=0)
                    {
                        A1=A2;
                        A2=B1;
                        B1=A1%A2;
                    }
                    temp=A2;
                    int i;
                    for(i=1; i<=temp; i++)
                    {
                        if(temp%i==0)
                        {
                            if(i>1)
                            {
                                printf(" ");
                            }
                            printf("%d",i);

                        }
                    }
                    printf("\n");
                }
                else if(A2>A1)
                {
                    B1=A2%A1;
                    while(B1!=0)
                    {
                        A2=A1;
                        A1=B1;
                        B1=A2%A1;
                    }
                    temp=A1;
                    int i;
                    for(i=1; i<=temp; i++)
                    {
                        if(temp%i==0)
                        {
                            if(i>1)
                            {
                                printf(" ");
                            }
                            printf("%d",i);

                        }
                    }
                    printf("\n");
                }
            }


            time--;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {

            int a,b,c,d,p_1[3]= {0},p_2[25]= {0},p_3[25]= {0};
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(a==0)
                break;
            p_1[0]=c;
            p_1[1]=b;
            p_1[2]=a;
            p_2[0]=c;
            p_2[1]=b;
            p_2[2]=a;
            int i,j,k,e=3;
            for(i=1; i<d; i++)
            {
                for(j=0; j<3; j++)
                {
                    for(k=0; k<e; k++)
                    {
                        p_3[j+k]+=p_1[j]*p_2[k];

                    }
                }
                e+=2;
                for(j=0; j<e; j++)
                {
                    p_2[j]=p_3[j];
                    p_3[j]=0;
                }

            }
            for(i=2*d; i>=0; i--)
            {
                if(i==0)
                    printf("%d\n",p_2[i]);
                else
                    printf("%d ",p_2[i]);
            }


        }
    }
    return 0;
}

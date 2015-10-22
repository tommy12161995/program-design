#include <stdio.h>
#include <stdlib.h>

int cal_damage();
int total=0;
int main()
{
    int X,Y,N,x,y,w,h;
    while(scanf("%d %d %d %d %d %d %d",&X ,&Y ,&N ,&x ,&y ,&w ,&h)!=EOF)
    {
        printf("%d\n",cal_damage(X, Y, N, x, y, w, h));
        total=0;
    }
    return 0;
}
int cal_damage(int X, int Y, int N, int x, int y, int w, int h)
{
    int i,j;
    if(N>=2)
    {
        for(i=X-N/2; i<=X+N/2; i++)
        {
            for(j=Y-N/2; j<=Y+N/2; j++)
            {
                if(x<=i&& i<=x+w && y<=j && j<=y+h)
                    total+=N;
            }
        }
   cal_damage( X-N*3/4, Y, N/2, x, y, w, h);
   cal_damage( X+N*3/4, Y, N/2, x, y, w, h);
   cal_damage( X, Y-N*3/4, N/2, x, y, w, h);
   cal_damage( X, Y+N*3/4, N/2, x, y, w, h);
   }

        return total;
   }

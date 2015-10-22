#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        char maze[2*n+1][2*n+4];
        memset(maze,'0',sizeof(maze));
        int i=0;
        while(fgets(maze[i],2*n,stdin)!=NULL&&i<2*n) {
            i++;
        }
        maze[3][3]='#';
        int x=3,y=3;
        while(1)
        {
            if(maze[x+2][y]=='0')
            {
                maze[x+2][y]='#';
                x+=2;
            }
            else if(maze[x-2][y]=='0')
            {
                maze[x-2][y]='#';
                x-=2;
            }
            else if(maze[x][y-2]=='0')
            {
                maze[x][y-2]='#';
                y-=2;
            }
            else if(maze[x][y+2]=='0')
            {
                maze[x][y+2]='#';
                y+=2;
            }
            else
            {
                while(1)
                {
                    if(maze[x+2][y]=='0')
                        break;
                    else if(maze[x-2][y]=='0')
                        break;
                    else if(maze[x][y-2]=='0')
                        break;
                    else if(maze[x][y+2]=='0')
                        break;
                    if(maze[x+2][y]=='#')
                    {
                        maze[x][y]='*';
                        x+=2;
                    }
                    else if(maze[x-2][y]=='#')
                    {
                        maze[x][y]='*';
                        x-=2;
                    }
                    else if(maze[x][y-2]=='#')
                    {
                        maze[x][y]='*';
                        y-=2;
                    }
                    else if(maze[x][y+2]=='#')
                    {
                        maze[x][y]='*';
                        y+=2;
                    }
                }
            }
            if(x==2*n-3&&y==2*n-3)
                break;
        }
        int j;
        for(i=0; i<2*n; i++)
        {
            for(j=0; j<2*n; j++)
                printf("%c",maze[i][j]);
            printf("\n");
        }
    }



    return 0;
}

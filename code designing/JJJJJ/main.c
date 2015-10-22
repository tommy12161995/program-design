#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,up,down,north,south,east,west,fnorth,fsouth,feast,fwest,fup,fdown;
    char k[10];
    char j[]="north";
    char j1[]="east";
    char j2[]="south";
    char j3[]="west";
    while(scanf("%d",&a)!=EOF&&a!=0)
    {
        up=1;
        north=2;
        west=3;
        down=6;
        south=5;
        east=4;
        fup=1;
        fnorth=2;
        fwest=3;
        fdown=6;
        fsouth=5;
        feast=4;

        for(i=0; i<a; i++)
        {
            scanf("%s",&k);
            if(!strcmp(k,j))
            {
                up=fsouth;
                north=fup;
                south=7-north;
                down=7-up;
            }
            if(!strcmp(k,j2))
            {
                up=fnorth;
                south=fup;
                down=7-up;
                north=7-south;
            }
            if(!strcmp(k,j1))
            {
                up=fwest;
                west=fdown;
                down=7-up;
                east=7-west;
            }
            if(!strcmp(k,j3))
            {
                up=feast;
                east=fdown;
                down=7-up;
                west=7-east;
            }
            fup=up;
            fdown=down;
            fnorth=north;
            fsouth=south;
            feast=east;
            fwest=west;
        }

        printf("%d\n",up);

    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int i, value=0;
    for(i=1; i<argc; i++)
        value+=atoi(argv[i]);
    printf("%d\n",value);
    return 0;
}

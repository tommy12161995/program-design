#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,x,y;
    scanf("%d",&n);

    while(scanf("%d %d",&a,&b)!=EOF){

    if(n==0)
       break;
    else if(a>=b&&(a+b)%2==0)
    {x=(a+b)/2;
    y=(a-b)/2;
    printf("%d %d\n",x,y);}

    else
        printf("impossible\n");

}

    return 0;
}

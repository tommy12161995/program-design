#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,input_1,input_2;
    scanf("%d",&n);
    while(scanf("%d %d",&input_1,&input_2)!=EOF)
    {

        if(input_1<input_2||(input_1+input_2)%2!=0)
            printf("impossible\n");
        else
        printf("%d %d\n",(input_1+input_2)/2,(input_1-input_2)/2);

    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],b[100];
    int i,j;
    for(i=0; i<=2; i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0; j<=2; j++)
    {
        i=j;
        b[j]=a[i];
    }
    int c[100]={0};
    for(i=0; i<=10; i++)
    {
        for(j=0; j<=10; j++)
        {
        c[i+j]=c[i+j]+a[i]*b[j];
        }
    }
    int k;
    k=j+i;
        for(k=0;k<=10;k++)
        printf("%d\n",c[k]);
    return 0;
}

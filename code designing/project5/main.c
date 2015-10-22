#include <stdio.h>
#include <stdlib.h>

void quick_sort(int a,int b,int n,int input[]);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int input[n];
        for(int i=0; i<n; i++)
            scanf("%d",&input[i]);
        quick_sort(0,n-1,n,input);
        for(int i=0; i<n; i++)
            printf("%d ",input[i]);
        printf("\n");
    }
    return 0;
}
void quick_sort(int left,int right,int n,int input[])
{

    if (!(left >= 0 && left < n && right >= 0 && right < n))
        return;
    if(left >= right)
        return ;
    int a=left,b=right;
    while(a != b)
    {
        if(input[a]>input[b] && b>a)
        {
            int temp;
            temp=input[a];
            input[a]=input[b];
            input[b]=temp;
            temp=a;
            a=b;
            b=temp;
        }
        else if(input[a]<input[b] && b<a)
        {
            int temp;
            temp=input[a];
            input[a]=input[b];
            input[b]=temp;
            temp=a;
            a=b;
            b=temp;
        }
        if(a>b)
            b++;
        else if(a<b)
            b--;
    }
    quick_sort(left,a-1,n,input);
    quick_sort(a+1,right,n,input);
}

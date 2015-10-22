#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int alen;
int blen;
char *line(char *num,int n)
{
    int ch,i=0;
    while((ch=getchar())!='\n') {
        if(i<n)
            num[i++]=ch;
        else {
            char *temp = malloc(sizeof(char) * n * 2);
            strncpy(temp, num, n);
            free(num);
            num = temp;
            n*=2;
            num[i++]=ch;
        }
    }
    num[i] = '\0';
    return num;
}
int num_add[300000];
int add(int a[],int b[])
{
    int i;
    int max=0;
    if(alen>blen)
        max = alen;
    else
        max = blen;
    memset(num_add,-1,sizeof(num_add));
    for(i=1; i<=max; i++) {
        num_add[i]=a[i]+b[i];
    }
    for(i=1; i<=max; i++) {
        if(num_add[i]>9) {
            if(i==max)
            {
                num_add[i+1]=0;
                max++;
            }
            num_add[i+1]+=num_add[i]/10;
            num_add[i]=num_add[i]%10;
        }
    }
    for(i=max; i>0; i--) {
        if(num_add[i]!=-1)
            printf("%d",num_add[i]);
    }
    printf("\n");
    return 0;
}
int num_minus[300000];

int minus(int a[],int b[])
{
    int i;
    int max=0;
    if(alen>blen)
        max = alen;
    else
        max = blen;
    memset(num_minus,-1,sizeof(num_minus));
    for(i=0; i<=max; i++) {
        num_minus[i]=a[i]-b[i];
    }
    for(i=0; i<=max; i++) {
        if(num_minus[i]<0) {
            num_minus[i+1]--;
            num_minus[i]+=10;
        }
    }
    for(i=max; i>0; i--) {
        if(num_minus[i]!=-1)
            printf("%d",num_minus[i]);
    }
    printf("\n");
    return 0;
}
int num_mult[300000];

int mult(int a[],int b[])
{
    int i,j,k,clen;
    clen=alen*blen;
    for(i=1; i<=alen; i++) {
        for(j=1; j<=blen; j++) {
            num_mult[i+j]+=a[i]*b[j];
        }
    }
    for(k=2; k<clen+2; k++) {
        if(num_mult[k]>9) {
            num_mult[k+1]+=num_mult[k]/10;
            num_mult[k]=num_mult[k]%10;
        }
    }
    int flag = 0;
    for(k=clen+2; k>1; k--) {
        if(flag == 0 && num_mult[k] == 0)
            continue;
        else
            flag = 1;
        printf("%d",num_mult[k]);
    }
    if(flag==0)
        printf("0");
    printf("\n");
    return 0;
}
int main ()
{
    char *err=(char*)malloc(10);
    char *num1=(char*)malloc(10); /*use char instead of int, getchar() reads everything to a char array*/
    char *math=(char*)malloc(10);
    char *num2=(char*)malloc(10);
    int num_1[100000],num_2[100000];
    char math_1[1];
    if(err==NULL)exit(1);
    if(num1==NULL) exit(1);
    if(num2==NULL) exit(1);
    int i,j,k;
    int flag=0;
    printf("請輸入第一個數：");
    num1=line(num1,10);
    printf("請輸入運算式：");
    math=line(math,10);
    printf("請輸入第二個數：");
    num2=line(num2,10);
    alen=0;
    blen=0;
    int str1,str2;
    str1=strlen(num1);
    str2=strlen(num2);
    for(i=0; i<str1; i++) {
        num1[i]=num1[i]-'0';
        alen++;
    }
    int a=alen;
    for(j=0; j<=i; j++) {
        num_1[j]=num1[a];
        a--;
    }
    for(i=0; i<=1; i++) {
        math_1[i]=math[i];
        if(math_1[i]=='+')
            flag=1;
        else if(math_1[i]=='-')
            flag=2;
        else if(math_1[i]=='*')
            flag=3;
    }
    for(i=0; i<str2; i++) {
        num2[i]=num2[i]-'0';
        blen++;
    }
    int b=blen;
    for(k=0; k<=i; k++) {
        num_2[k]=num2[b];
        b--;
    }
    if(flag==1)
        add(num_1,num_2);
    else if(flag==2)
        minus(num_1,num_2);
    else if(flag==3)
        mult(num_1,num_2);
    free(num1);
    free(num2);
    return 0;
}

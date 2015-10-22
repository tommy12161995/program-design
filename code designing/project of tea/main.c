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
    int flag = 0;
    for(i=max; i>0; i--) {
        if(flag == 0 && num_minus[i] == 0)
            continue;
        else
            flag = 1;
        printf("%d",num_minus[i]);
    }
    if(flag==0)
        printf("0");
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

    char *num1=(char*)malloc(3000); /*use char instead of int, getchar() reads everything to a char array*/
    char *num2=(char*)malloc(3000);
    char *num3=(char*)malloc(3000);
    int num_1[100000],num_2[100000];
    if(num1==NULL) exit(1);
    int i,j,k;
    int flag=0;
    num1=line(num1,3000);
    for(i=0; i<strlen(num1); i++)
    {
        if(num1[i]=='+')
        {
            flag=1;
            break;
        }
        else if(num1[i]=='-')
        {
            flag=2;
            break;
        }
        else if(num1[i]=='*')
        {
            flag=3;
            break;
        }
    }
    alen=0;
    blen=0;
    int str1,str2;
    int a,b;
    num3=strtok(num1,"+-*");
    str1=strlen(num3)-1;
    char *number1=malloc(sizeof(char)*str1+2);
    strcpy(number1,num3);
    if(num3!=NULL)
        num3=strtok(NULL,"\0");
    str2=strlen(num3)-1;
    char *number2=malloc(sizeof(char)*str1+2);
    strcpy(number2,num3+1);
    for(i=0; i<str1; i++)
    {
        number1[i]=number1[i]-'0';
        alen++;
    }
    a=alen;
    for(j=0; j<=i; j++)
    {
        num_1[j]=number1[a];
        a--;
    }
    for(i=0; i<str2; i++)
    {
        number2[i]=number2[i]-'0';
        blen++;
    }
     b=blen;
    for(k=0; k<=i; k++)
    {
        num_2[k]=number2[b];
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false -1
int email_check(char email[]);

struct part{
      char email[100];
      char email_repeat[100];
      char user_name[100];
      char domain_name[100];
};

int user_name_cmp(struct part *a,struct part *b);
int domain_name_cmp(struct part *a,struct part *b);

int main()
{
     char input[100];
    printf("請輸入你要輸入幾個e-mail.\n");
    while(fgets(input,100,stdin)!=NULL)
    {
        int n;
        if(atoi(input)<=0)
        {
            printf("請輸入正整數\n");
            continue;
        }
        else
            n=atoi(input);
        struct part group[100];
        char *pch;
        int count=0,check,i;
        while(n--)
        {
            fgets(group[count].email,100,stdin);
            check=email_check(group[count].email);
            if(check==false)
                memset(group[count].email,'\0',sizeof(group[count].email));
            else if(check == true)
                {
                    strcpy(group[count].email_repeat,group[count].email);
                    pch=strtok(group[count].email_repeat,"@");
                    strcpy(group[count].user_name,pch);
                    pch=strtok(NULL,"\n");
                    strcpy(group[count].domain_name,pch);
                    count++;
                }
        }
        qsort(group,count,sizeof(struct part),user_name_cmp);
        printf("按照username排序\n");
        for(i=0;i<count;i++)
            printf("#%d. %s",i+1,group[i].email);
        printf("\n");
        qsort(group,count,sizeof(struct part),domain_name_cmp);
        printf("按照domainname排序\n");
        for(i=0;i<count;i++)
            printf("#%d. %s",i+1,group[i].email);
        printf("\n");
    }
    return 0;
}
int email_check(char input[100])
{
    int flag=0;
    char email[100];
    strcpy(email, input);
    char *mouse=strchr(email,'@');
    while(mouse!=NULL)
    {
        flag++;
        mouse=strchr(mouse+1,'@');
    }
    if(flag!=1)
        {
            printf("輸入了兩個以上或你沒輸入@\n");
            return false;
        }

    char user_name[100],domain_name[100];
    char *pch;
    pch=strtok(email,"@");
    strcpy(user_name,pch);
    pch=strtok(NULL,"\n");
    if(pch == NULL)
        {
        printf("你的@在username的第一格\n");
        return false;
    }
    strcpy(domain_name,pch);
    if(domain_name[0]=='@')
        {
            printf("你的@在domainname的第一格\n");
            return false;
        }


    int len_user_number,len_domain_number,count=0,i;
    len_user_number=strlen(user_name);
    len_domain_number=strlen(domain_name);
    for(i=0;i<len_user_number;i++)
    {
        if(user_name[i]=='.')
            count++;


        if(user_name[i]=='.'&&user_name[i+1]=='.')
            {
                printf("你的.連在一起\n");
                return false;
            }
        if(user_name[0]=='.'||user_name[len_user_number-1]=='.')
            {
                printf("你的.在username的字首或字尾\n");
                return false;
            }
        if((user_name[i]>='A'&&user_name[i]<='Z')||(user_name[i]>='a'&&user_name[i]<='z')||(user_name[i]<='9'&&user_name[i]>='0')||user_name[i]=='.'||user_name[i]=='_')
            continue;
        else
            {
                printf("你有非法字元\n");
                return false;
            }

    }
    if(count == 0)
    {
        printf("你的username沒有.\n");
        return false;
    }
    count=0;
    for(i=0;i<len_domain_number;i++)
    {
        if(domain_name[i]=='.')
            count++;
        if(domain_name[i]=='.'&&domain_name[i+1]=='.')
            {
                printf("你的.連在一起\n");
                return false;
            }
        if(domain_name[0]=='.'||domain_name[len_domain_number-1]=='.')
            {
                printf("你的.在domainname的字首或字尾\n");
                return false;
            }
        if((domain_name[i]>='A'&&domain_name[i]<='Z')||(domain_name[i]>='a'&&domain_name[i]<='z')||(domain_name[i]<='9'&&domain_name[i]>='0')||domain_name[i]=='.'||domain_name[i]=='_')
            continue;
        else
            {
                printf("你有非法字元\n");
                return false;
            }
    }
    if(count == 0)
    {
        printf("你的domainname沒有.\n");
        return false;
    }
    return true;
}
int user_name_cmp(struct part *a,struct part *b)
    {
        return strcmp(a->user_name,b->user_name);
    }
int domain_name_cmp(struct part *a,struct part *b)
    {
        return strcmp(a->domain_name,b->domain_name);
    }


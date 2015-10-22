#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct part
{
    char name[16];
    int age;
    enum {female,male} sex;
};
int main()
{
    char people[100];
    int capacity = 1,n=0;
    struct part *ptr1=(struct part *)malloc(sizeof(struct part) * capacity);
    while(fgets(people,100,stdin)!=NULL)
    {
        if(n >= capacity)
        {
            capacity*=2;
            printf("queue/stack full,allocate double size %d\n",capacity);
            struct part *ptr2=(struct part *)malloc(sizeof(struct part) * capacity);
            memcpy(ptr2,ptr1,sizeof(struct part) * capacity/2);
            free(ptr1);
            ptr1=ptr2;
        }
        char *num1;
        num1=strtok(people,",");
        char *name=(char*)malloc(sizeof(char)*(strlen(num1)+1));
        int flag=0;
        for(int i=0;i<strlen(num1);i++)
        {
            if(num1[i]!='"')
            {
                name[flag]=num1[i];
                flag++;
            }
        }
        strcpy((ptr1+n)->name,name);

        //printf("%s , %s\n",ptr1+n->name,num1);
        char *num2;
        num2=strtok(NULL,",");
        (ptr1+n)->age=atoi(num2);
        //printf("%d\n",ptr1->age);
        char *num3;
        num3=strtok(NULL,"\n");

        for(int i=0; i<strlen(num3); i++)
        {
            //printf("%s\n", num3);
            if(num3[i]=='f'||num3[i]=='F')
            {
                (ptr1+n)->sex=female;
                break;
            }
            else if(i==strlen(num3)-1)
                (ptr1+n)->sex=male;
        }
        //printf("%d\n",ptr1->sex);
        n++;

    }
    for(int i=0; i<n; i++)
    {
        printf("name=%s,age=%d,sex=%d\n",(ptr1+i)->name,(ptr1+i)->age,(ptr1+i)->sex);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

ListNode *data_insert(ListNode *head)
{
    ListNode *input_data = malloc(sizeof(ListNode));
    printf("Please input student's name.(10­Ó¦r¥H¤º)\n");
    fgets(input_data->data.name,10,stdin);
    int len=strlen(input_data->data.name);
    input_data->data.name[len-1]='\0';
    printf("Please input ID.\n");
    scanf("%d",&input_data->data.student_ID);
    printf("Please input grade.(Chinese Math English Science Social_study)\n");
    scanf("%d %d %d %d %d",
          &input_data->data.chinese, &input_data->data.math,
          &input_data->data.english, &input_data->data.science,
          &input_data->data.social_study);
    input_data->data.sum=input_data->data.chinese+input_data->data.math
                         +input_data->data.english+input_data->data.science+input_data->data.social_study;
    ListNode *q = head;
    while(q != NULL)
    {
        if(q->data.student_ID == input_data->data.student_ID)
        {
            printf("This ID has existed!\n");
            return head;
        }
        q=q->next;
    }
    if (head == NULL)
    {
        head = input_data;
        return head;
    }
    else
    {
        ListNode *p = head,*prev=NULL;
        while (p != NULL)
        {
            if (p->next == NULL && p->data.student_ID < input_data->data.student_ID)
            {
                p->next = input_data;
                return head;
                break;
            }

            else if(p->next == NULL && p->data.student_ID > input_data->data.student_ID && prev == NULL)
            {
                input_data->next=p;
                head=input_data;
                return head;
                break;
            }
            else if(p->next == NULL && p->data.student_ID > input_data->data.student_ID && prev != NULL)
            {
                prev->next=input_data;
                input_data->next=p;
                return head;
                break;
            }
            else if (p->next->data.student_ID > input_data->data.student_ID && prev !=NULL)
            {
                input_data->next = p->next;
                p->next = input_data;
                return head;
                break;
            }
            else if(p->data.student_ID > input_data->data.student_ID && prev == NULL)
            {
                input_data->next=p;
                head=input_data;
                return head;
                break;
            }
            prev=p;
            p = p->next;
        }

    }
}
ListNode *data_delete(ListNode *head)
{
    printf("Please input student ID you want to delete.\n");
    int ID;
    scanf("%d", &ID);
    ListNode *p = head;
    if (p == NULL)
    {
        // no linked list has been created
        printf("You don't have data.\n");
        head = NULL;

        return head;
    }

    ListNode *prev = NULL;
    while (p != NULL)                 // linked list existed
    {
        if (p->data.student_ID == ID)   // ID found
        {
            if (p->next == NULL)          // last node
            {
                if (prev != NULL)
                    prev->next = NULL;
                free(p);

                return prev == NULL ? NULL : head;
            }
            else if (prev == NULL)     // first node
            {
                head = p->next;
                free(p);

                return head;
            }
            else     // between first and last
            {
                prev->next = p->next;
                free(p);

                return head;
            }
        }

        prev = p;
        p = p->next;
    }

    printf("ID not found.\n");
    return head;
}
ListNode *data_edit(ListNode *head)
{
    printf("Please input student ID you want to edit.\n");
    int ID;
    scanf("%d",&ID);
    ListNode *p=head;
    if (p == NULL)
    {
        printf("You don't have data.\n");
        head = NULL;

        return head;
    }
    while (p != NULL)
    {
        if (p->data.student_ID == ID)
        {
            printf("%d %d %d %d %d %d\n",p->data.student_ID,
                   p->data.chinese, p->data.math, p->data.english,
                   p->data.science,p->data.social_study);
            printf("Please input what grade do you want to edit.\n");
            printf("1.Chinese\n");
            printf("2.Math\n");
            printf("3.English\n");
            printf("4.Science\n");
            printf("5.Social study\n");
            int command;
            scanf("%d",&command);
            if(command == 1)
            {
                printf("Please input Chinese grade.\n");
                int grade;
                scanf("%d",&grade);
                p->data.chinese=grade;
                p->data.sum=p->data.chinese+p->data.math
                            +p->data.english+p->data.science+p->data.social_study;
            }
            else if(command == 2)
            {
                printf("Please input math grade.\n");
                int grade;
                scanf("%d",&grade);
                p->data.math=grade;
                p->data.sum=p->data.chinese+p->data.math
                            +p->data.english+p->data.science+p->data.social_study;
            }
            else if(command == 3)
            {
                printf("Please input English grade.\n");
                int grade;
                scanf("%d",&grade);
                p->data.english=grade;
                p->data.sum=p->data.chinese+p->data.math
                            +p->data.english+p->data.science+p->data.social_study;
            }
            else if(command == 4)
            {
                printf("Please input science grade.\n");
                int grade;
                scanf("%d",&grade);
                p->data.science=grade;
                p->data.sum=p->data.chinese+p->data.math
                            +p->data.english+p->data.science+p->data.social_study;
            }
            else if(command == 5)
            {
                printf("Please input social study grade.\n");
                int grade;
                scanf("%d",&grade);
                p->data.social_study=grade;
                p->data.sum=p->data.chinese+p->data.math
                            +p->data.english+p->data.science+p->data.social_study;
            }
            printf("This is the student grade now.\n");
            printf("Name:%s ID:%d Chinese:%d Math:%d English:%d Science:%d Social_study:%d Sum of grade:%d\n",p->data.name,p->data.student_ID,
                   p->data.chinese, p->data.math, p->data.english,
                   p->data.science,p->data.social_study,p->data.sum);
            return head;
        }
        p = p->next;
    }

    printf("ID not found.\n");
    return head;
}
ListNode *data_search(ListNode *head)
{
    printf("Please input student ID you want to search.\n");
    int ID;
    scanf("%d",&ID);
    ListNode *p=head;
    if (p == NULL)
    {
        printf("You don't have data.\n");
        head = NULL;

        return head;
    }
    while (p != NULL)
    {
        if (p->data.student_ID == ID)
        {
            printf("This is the student's grade.\n");
            printf("Name:%s ID:%d Chinese:%d Math:%d English:%d Science:%d Social_study:%d Sum of grade:%d\n",p->data.name,p->data.student_ID,
                   p->data.chinese, p->data.math, p->data.english,
                   p->data.science,p->data.social_study,p->data.sum);
            return head;
            break;
        }
        p=p->next;
    }
    printf("ID not found.\n");
    return head;
}
ListNode *data_sort(ListNode *head,int flag)
{
    printf("Please input what grade do you want to sort.\n");
    printf("1.Chinese\n");
    printf("2.Math\n");
    printf("3.English\n");
    printf("4.Science\n");
    printf("5.Social study\n");
    printf("6.Sum of grade\n");
    if(head == NULL)
    {
        printf("You don't have data.\n");
        return head;
    }
    if(head->next == NULL)
    {
        printf("You only have one data.\n");
        return head;
    }

    int command;
    ListNode *p=head,*q=head->next;
    scanf("%d",&command);
    if(command == 1)
    {
        for(int i=0; i<flag; i++)
        {
            for(int j=0; j<flag-1; j++)
            {
                if(p->data.chinese<q->data.chinese)
                {
                    data_struct temp;
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                p=p->next;
                q=q->next;
            }
            p=head;
            q=head->next;
        }
        return head;
    }
    else if(command == 2)
    {
        for(int i=0; i<flag; i++)
        {
            for(int j=0; j<flag-1; j++)
            {
                if(p->data.math<q->data.math)
                {
                    data_struct temp;
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                p=p->next;
                q=q->next;
            }
            p=head;
            q=head->next;
        }
        return head;
    }
    else if(command == 3)
    {
        for(int i=0; i<flag; i++)
        {
            for(int j=0; j<flag-1; j++)
            {
                if(p->data.english<q->data.english)
                {
                    data_struct temp;
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                p=p->next;
                q=q->next;
            }
            p=head;
            q=head->next;
        }
        return head;
    }
    else if(command == 4)
    {
        for(int i=0; i<flag; i++)
        {
            for(int j=0; j<flag-1; j++)
            {
                if(p->data.science<q->data.science)
                {
                    data_struct temp;
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                p=p->next;
                q=q->next;
            }
            p=head;
            q=head->next;
        }
        return head;
    }
    else if(command == 5)
    {
        for(int i=0; i<flag; i++)
        {
            for(int j=0; j<flag-1; j++)
            {
                if(p->data.social_study<q->data.social_study)
                {
                    data_struct temp;
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                p=p->next;
                q=q->next;
            }
            p=head;
            q=head->next;
        }
        return head;
    }
    else if(command == 6)
    {
        for(int i=0; i<flag; i++)
        {
            for(int j=0; j<flag-1; j++)
            {
                if(p->data.sum<q->data.sum)
                {
                    data_struct temp;
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                p=p->next;
                q=q->next;
            }
            p=head;
            q=head->next;
        }
        return head;
    }
}

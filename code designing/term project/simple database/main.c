#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"
#include "struct.h"
int main()
{
    printf("Please choose what do you want to do?\n");
    printf("0.exit(請按0跳出，否則檔案不會儲存。)\n");
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.edit\n");
    printf("4.search\n");
    printf("5.sorting\n");
    int command;
    ListNode *head, *tail;
    head = NULL;
    int flag=0;
    FILE *fp;
    fp=fopen("input.txt","w");
    while (scanf("%d", &command) != EOF)
    {
        getchar();
        if (command == 0)
        {
            ListNode *p = head;
            while (p != NULL)
            {
                fprintf(fp,"Name:%s ID:%d Chinese:%d Math:%d English:%d Science:%d Social_study:%d Sum of grade:%d\n",p->data.name, p->data.student_ID,
                        p->data.chinese, p->data.math, p->data.english, p->data.science,
                        p->data.social_study,p->data.sum);
                p = p->next;
            }
            fclose(fp);
            break;
        }
        ListNode *input_data = malloc(sizeof(ListNode));
        input_data->next = NULL;
        if (command == 1)
        {
            head = data_insert(head);
            flag++;
        }
        else if (command == 2)
        {
            head = data_delete(head);
            flag--;
        }
        else if(command == 3)
            head = data_edit(head);
        else if(command == 4)
            head = data_search(head);
        else if(command == 5)
            head = data_sort(head,flag);
        else
        {
            printf("Error! Please input again.\n");
        }
        ListNode *t = head;
        printf("\n");
        printf("There are your data.\n");
        while (t != NULL)
        {
            printf("Name:%s ID:%d Chinese:%d Math:%d English:%d Science:%d Social_study:%d Sum of grade:%d\n",t->data.name, t->data.student_ID,
                   t->data.chinese, t->data.math, t->data.english, t->data.science,
                   t->data.social_study,t->data.sum);
            t = t->next;
        }
        printf("\n");
        printf("Please choose what do you want to do?\n");
        printf("0.exit(請按0跳出，否則檔案不會儲存。)\n");
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.edit\n");
        printf("4.search\n");
        printf("5.sorting\n");
    }
    return 0;
}


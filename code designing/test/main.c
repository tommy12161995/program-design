#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentdata
{
    char name[30];
    char id[30];
    char Calculus[20];
    char Program[20];
    char Discrete[20];
    char Probability[30];
    char Total[30];
};
typedef struct node
{
    struct studentdata data ;
    struct node *next;
} Node;


int main()
{
    Node *startptr, *newptr, *currentptr;
    startptr=NULL;
    newptr = malloc(sizeof(Node));
    FILE *fp1;
    FILE *fp2;
    fp1=fopen("Project3_sample.txt","r");
//   fp2=fopen("answer.txt","w");
    fscanf(fp1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",newptr->data.name,newptr->data.id,newptr->data.Calculus,newptr->data.Program,newptr->data.Discrete,newptr->data.Probability,newptr->data.Total);

     printf("to choose\n");
    printf("A.list\nB.insert\nC.delete\nD.sort\nE.edit\nF.exit");
    char flag;
    scanf("%c",&flag);
    /*if(flag=='A')
     {
    f
        }*/
    if(flag=='B')
    {
        scanf("%s\t%s\t%s\t%s\t%s\t%s\t\n",currentptr->data.name,currentptr->data.id, currentptr->data.Calculus,currentptr->data.Program,currentptr->data.Discrete,currentptr->data.Probability);
        if(newptr==NULL)
        {
            startptr=newptr;
        }
        else
        {
            currentptr = startptr;
            while (currentptr != NULL)
            {
                if (currentptr->next == NULL)
                {
                    currentptr->next = newptr;
                    break;
                }

                currentptr = currentptr->next;
            }
        }
        currentptr = startptr;
        printf("%s\t%s\t%s\t%s\t%s\t%s\t\n",currentptr->data.name,currentptr->data.id,currentptr->data.Calculus,currentptr->data.Program,currentptr->data.Discrete,currentptr->data.Probability);
    }




    return 0;
}

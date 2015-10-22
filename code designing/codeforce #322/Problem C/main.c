#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int level;
    int value;
} part;
int cmp(const void *a,const void *b);
int main()
{
    int skill_number,units;
    while(scanf("%d %d",&skill_number,&units)!=EOF)
    {
        part character[skill_number];
        for(int i=0; i<skill_number; i++)
        {
            scanf("%d",&character[i].level);
            character[i].value=10-character[i].level%10;
            character[i].level/=10;
        }
        qsort(character,skill_number,sizeof(part),cmp);
        int temp=0;
        while(units>0)
        {
            for(int i=0; i<skill_number; i++)
            {
                if(character[i].level<10)
                {
                    units-=character[i].value;
                    if(units<0)
                        break;
                    else
                    {
                        character[i].level++;
                        character[i].value=10;
                    }
                }
                else
                    temp++;
            }
            if(temp == skill_number)
                break;
            else
                temp=0;

        }
        int max=0;
        for(int i=0; i<skill_number; i++)
            max+=character[i].level;
        printf("%d\n",max);
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    return ((part *)a)->value - ((part *)b)->value;
}

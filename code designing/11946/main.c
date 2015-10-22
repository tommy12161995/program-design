#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {

        getchar();
        while(n--)
        {
              char input[82];
             while(fgets(input,82,stdin) != NULL) {
                if(input[0] == '\n') {
                    if(n != 0)
                        printf("\n");
                    break;
                }
            int i,len=0;
            len=strlen(input);
            for(i=0; i<len; i++)
            {
                switch(input[i])
                {
                case'0':
                    input[i]='O';
                    break;
                case'1':
                    input[i]='I';
                    break;
                case'2':
                    input[i]='Z';
                    break;
                case'3':
                    input[i]='E';
                    break;
                case'4':
                    input[i]='A';
                    break;
                case'5':
                    input[i]='S';
                    break;
                case'6':
                    input[i]='G';
                    break;
                case'7':
                    input[i]='T';
                    break;
                case'8':
                    input[i]='B';
                    break;
                case'9':
                    input[i]='P';
                    break;
                }
                printf("%c",input[i]);
            }
        }

    }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char numbers[]= {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char types[]= {'C','D','H','S'};
int hand_card[4][13]={0};
int hand_player1[4][13]={0};
int hand_player2[4][13]={0};
int shared_card[4][13]={0};
int temp_card[4][13]={0};

void shuffling(int n)
{
    int number, type;
    int i=0, j;

    while(i<n)
    {
        number=rand() % 13;
        type=rand() % 4;

        if(hand_card[type][number]==0)
        {
            hand_card[type][number]=1;
            printf("%c%c ",numbers[number],types[type]);


            temp_card[0][i] = numbers[number];

            if(type==0) temp_card[1][i] = types[type];
            else if(type==1) temp_card[2][i] = types[type];
            else if(type==2) temp_card[3][i] = types[type];
            else if(type==3) temp_card[4][i] = types[type];

            i++;
        }
    }
    printf("\n\n");
}

void save_card()
{

}

void deal_card()
{


}

int main()
{
    printf("Welcome\n\n");
    printf("�O�_�}�l�C��?\n  1.�O �}�l�C��\n  2.�_ ���}�C��\n\n");
    int choice, i, j;

    printf("���(�п�J1��2): ");
    while(EOF!=scanf("%d", &choice))
    {
        if(choice==2)
        {
            printf("\nSee you next time\n");
            break;
        }

        else if(choice==1)
        {
            srand(time(NULL));
            int round;

            for(round=0; round<5; round++)
            {
                printf("#round %d\n\n", (round+1));

                printf("���a��P:\n");
                shuffling(2);
                for(i=0; i<4; i++){
                    for(j=0; j<13; j++){
                        hand_player1[i][j]=temp_card[i][j];
                    }
                }

                printf("����P:\n");
                shuffling(2);
                for(i=0; i<4; i++){
                    for(j=0; j<13; j++){
                        hand_player2[i][j]=temp_card[i][j];
                    }
                }

                printf("���P:\n");
                shuffling(5);
                for(i=0; i<4; i++){
                    for(j=0; j<13; j++){
                        shared_card[i][j]=temp_card[i][j];
                    }
                }

                printf("\n\n");

                printf("���a��P�[���P(�w�Ƨ�):\n");

                for(i=0; i<4; i++){
                    for(j=0; j<13; j++){
                        printf("%c", hand_player1[i][j]);
                    }
                    printf("\n");
                }


                printf("����P�[���P(�w�Ƨ�):\n");


                printf("\n\n");
                printf("***************************************");
                printf("\n\n");

            }

        }
        printf("==SEE YOU NEXT TIME==\n\n");
        break;
    }
}

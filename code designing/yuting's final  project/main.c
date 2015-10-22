#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char numbers[]= {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char types[]= {'C','D','H','S'};
int hand_card[5][13]= {0};
int hand_player1[5][13]= {0};
int hand_player2[5][13]= {0};
int shared_card[5][13]= {0};
int temp_card[5][13]= {0};

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
char change_number1(int i)
{
    char number[14] = {' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    return number[i];
}
char change_type(int i)
{
    char type1[5] = {' ', 'C', 'D', 'H', 'S'};
    return type1[i];
}

int deal_card(int a[])
{
    int b[7]= {0},c[7]= {0},i,j=0,k=0;
    for(i=0; i<14; i++)
    {
        if(i%2==0)
        {
            switch(a[i])
            {
            case 65:
                b[j]=1;
                break;
            case 50:
                b[j]=2;
                break;
            case 51:
                b[j]=3;
                break;
            case 52:
                b[j]=4;
                break;
            case 53:
                b[j]=5;
                break;
            case 54:
                b[j]=6;
                break;
            case 55:
                b[j]=7;
                break;
            case 56:
                b[j]=8;
                break;
            case 57:
                b[j]=9;
                break;
            case 84:
                b[j]=10;
                break;
            case 74:
                b[j]=11;
                break;
            case 81:
                b[j]=12;
                break;
            case 75:
                b[j]=13;
                break;
            }
            j++;
        }
        else if(i%2==1)
        {
            switch(a[i])
            {
            case 67:
                c[k]=1;
                break;
            case 68:
                c[k]=2;
                break;
            case 72:
                c[k]=3;
                break;
            case 83:
                c[k]=4;
                break;
            }
            k++;
        }
    }

    int n,type0[5]= {0},number[5]= {0},flag=0;
    /*Straight flush*/
    for(i=0; i<3; i++)
    {
        flag=0;
        type0[0]=c[i];
        number[0]=b[i];
        for(j=i+1; j<7; j++)
        {
            if(type0[0]==c[j])
            {
                flag++;
                type0[flag]=c[j];
                number[flag]=b[j];
                if(flag==4)
                    break;
            }
        }
        if(flag==4)
        {
            if(number[0]+1==number[1]&&number[1]+1==number[2]&&number[2]+1==number[3]&&number[3]+1==number[4])
            {
                for(j=0; j<=4; j++)
                {
                    printf("%c%c ",change_number1(number[j]),change_type(type0[j]));
                }
                printf("Straight flush\n");
                return 9;
            }
            else if(number[0]==1&&number[1]==10&&number[2]==11&&number[3]==12&&number[4]==13)
            {
                printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(number[1]),change_type(type0[1]),change_number1(number[2]),change_type(type0[2]),change_number1(number[3]),change_type(type0[3]),change_number1(number[4]),change_type(type0[4]),change_number1(number[0]),change_type(type0[0]));
                printf("Straight flush\n");
                return 9;
            }
            break;
        }
    }
    n=4;
    while(n--)   /*Four of a kind*/
    {
        if(b[n]==b[n+1]&&b[n+1]==b[n+2]&&b[n+2]==b[n+3])
        {
            if(n==3)
            {
                printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[3]),change_type(c[3]),change_number1(b[4]),change_type(c[4]),change_number1(b[5]),change_type(c[5]),change_number1(b[6]),change_type(c[6]),change_number1(b[0]),change_type(c[0]));
                printf("Four of a kind\n");
                return 8;
                break;
            }
            else
            {
                for(i=n; i<=n+4; i++)
                {
                    printf("%c%c ",change_number1(b[n]),change_type(c[n]));
                }
                printf("Four of a kind\n");
                return 8;
                break;
            }
        }
        else
            continue;
    }
    for(i=0; i<=4; i++)   /*Full House*/
    {
        if(b[i]==b[i+1]&&b[i+1]==b[i+2])
        {
            for(j=i+3; j<=5; j++)
            {
                if(b[j]==b[j+1])
                {
                    printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[i+2]),change_type(c[i+2]),change_number1(b[j]),change_type(c[j]),change_number1(b[j+1]),change_type(c[j+1]));
                    printf("Full House\n");
                    return 7;
                    break;
                }
            }
            for(j=i-1; j>=1; j--)
            {
                if(b[j]==b[j-1])
                {
                    printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[i+2]),change_type(c[i+2]),change_number1(b[j]),change_type(c[j]),change_number1(b[j-1]),change_type(c[j-1]));
                    printf("Full House\n");
                    return 7;
                    break;
                }
            }
        }
    }
    /*Flush*/
    for(i=0; i<3; i++)
    {
        flag=0;
        type0[0]=c[i];
        number[0]=b[i];
        for(j=i+1; j<7; j++)
        {
            if(type0[0]==c[j])
            {
                flag++;
                type0[flag]=c[j];
                number[flag]=b[j];
            }
            if(flag==4)
                break;
        }
        if(flag==4)
        {
            for(j=0; j<=4; j++)
            {
                printf("%c%c ",change_number1(number[j]),change_type(type0[j]));
            }
            printf("Flush\n");
            return 6;
        }
    }
    /*Straight*/
    for(i=0; i<3; i++)
    {
        flag=0;
        number[0]=b[i];
        type0[0]=c[i];
        for(j=i+1; j<7; j++)
        {
            if(b[i]+1+flag==b[j])
            {
                flag++;
                number[flag]=b[j];
                type0[flag]=c[j];
            }
            if(flag==4)
                break;
        }
        if(flag==4)
        {
            for(j=0; j<=4; j++)
            {
                printf("%c%c ",change_number1(number[j]),change_type(type0[j]));
            }
            printf("Straight\n");
            return 5;
        }
        else if(number[0]==1&&number[1]==10&&number[2]==11&&number[3]==12&&number[4]==13)
        {
            printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(number[1]),change_type(type0[1]),change_number1(number[2]),change_type(type0[2]),change_number1(number[3]),change_type(type0[3]),change_number1(number[4]),change_type(type0[4]),change_number1(number[0]),change_type(type0[0]));
            printf("Straight\n");
            return 5;
        }
        break;
    }
    for(i=0; i<=4; i++)   /*Three of a kind*/
    {
        if(b[i]==b[i+1]&&b[i+1]==b[i+2])
        {
            if(i<=2)
            {
                printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[i+2]),change_type(c[i+2]),change_number1(b[i+3]),change_type(c[i+3]),change_number1(b[i+4]),change_type(c[i+4]));
                printf("Three of a kind\n");
                return 4;
                break;
            }
            else
            {
                printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[i+2]),change_type(c[i+2]),change_number1(b[i-1]),change_type(c[i-1]),change_number1(b[i-2]),change_type(c[i-2]));
                printf("Three of a kind\n");
                return 4;
                break;
            }
        }
    }
    for(i=0; i<=3; i++)   /*Two pairs*/
    {
        if(b[i]==b[i+1])
        {
            for(j=i+2; j<=5; j++)
            {
                if(b[j]==b[j+1])
                {
                    if(j==5&&i==3)
                    {
                        printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[j]),change_type(c[j]),change_number1(b[j+1]),change_type(c[j+1]),change_number1(b[0]),change_type(c[0]));
                        printf("Two pairs\n");
                        return 3;
                        break;
                    }
                    else if(j==5&&i!=3)
                    {
                        printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[j]),change_type(c[j]),change_number1(b[j+1]),change_type(c[j+1]),change_number1(b[i+2]),change_type(c[i+2]));
                        printf("Two pairs\n");
                        return 3;
                        break;
                    }
                    else
                    {
                        printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[j]),change_type(c[j]),change_number1(b[j+1]),change_type(c[j+1]),change_number1(b[j+2]),change_type(c[j+2]));
                        printf("Two pairs\n");
                        return 3;
                        break;
                    }
                }
            }
        }
    }
    for(i=0; i<=5; i++)   /*One pair*/
    {
        if(b[i]==b[i+1])
        {
            if(i>=3)
            {
                printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[0]),change_type(c[0]),change_number1(b[1]),change_type(c[1]),change_number1(b[2]),change_type(c[2]));
                printf("One pair\n");
                return 2;
                break;
            }
            else
            {
                printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[i]),change_type(c[i]),change_number1(b[i+1]),change_type(c[i+1]),change_number1(b[i+2]),change_type(c[i+2]),change_number1(b[i+3]),change_type(c[i+3]),change_number1(b[i+4]),change_type(c[i+4]));
                printf("One pair\n");
                return 2;
                break;
            }
        }
    }
    /*High Card*/
    printf("%c%c %c%c %c%c %c%c %c%c ",change_number1(b[6]),change_type(c[6]),change_number1(b[5]),change_type(c[5]),change_number1(b[4]),change_type(c[4]),change_number1(b[3]),change_type(c[3]),change_number1(b[2]),change_type(c[2]));
    printf("High Card\n");
    return 1;
}

void bubblesort(int a[])
{
    int i,j=0,k=0,color[7]= {0},number[7]= {0};
    for(i=0; i<14; i++)
    {
        if(i%2==0)
        {
            if(a[i]=='A')
                a[i]-=18;
            else if(a[i]=='T')
                a[i]-=26;
            else if(a[i]=='J')
                a[i]-=16;
            else if(a[i]=='Q')
                a[i]-=21;
            else if(a[i]=='K')
                a[i]-=14;
            number[j]=a[i];
            j++;
        }
        else
        {
            color[k]=a[i];
            k++;
        }
    }
    int temp1,temp2;
    int m,l;
    for(m=0; m<6; m++)
    {
        for(l=0; l<7-(m+1); l++)
        {
            if(number[l]>number[l+1])
            {
                temp1=number[l];
                number[l]=number[l+1];
                number[l+1]=temp1;
                temp2=color[l];
                color[l]=color[l+1];
                color[l+1]=temp2;
            }
        }
    }
    for(m=0; m<6; m++)
    {
        for(i=0; i<7-(m+1); i++)
        {
            if(number[i]==number[i+1])
            {
                if(color[i]>color[i+1])
                {
                    temp2=color[i];
                    color[i]=color[i+1];
                    color[i+1]=temp2;
                }
            }
        }
    }
    j=0;
    k=0;
    for(i=0; i<14; i++)
    {
        if(i%2==0)
        {
            if(number[j]==47)
                number[j]+=18;
            else if(number[j]==58)
                number[j]+=26;
            else if(number[j]==59)
                number[j]+=16;
            else if(number[j]==60)
                number[j]+=21;
            else if(number[j]==61)
                number[j]+=14;
            a[i]=number[j];
            j++;
        }
        else
        {
            a[i]=color[k];
            k++;
        }
    }
}
int main()
{
    printf("Welcome\n\n");
    printf("是否開始遊戲?\n  1.是 開始遊戲\n  2.否 離開遊戲\n\n");
    int choice, i, j;

    printf("選擇(請輸入1或2): ");

    while(EOF!=scanf("%d", &choice))
    {
        printf("\n\n");

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

                printf("玩家手牌:\n");
                shuffling(2);
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        hand_player1[i][j]=temp_card[i][j];
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        temp_card[i][j]=0;
                    }
                }

                printf("對手手牌:\n");
                shuffling(2);
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        hand_player2[i][j]=temp_card[i][j];
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        temp_card[i][j]=0;
                    }
                }

                printf("公牌:\n");
                shuffling(5);
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        shared_card[i][j]=temp_card[i][j];
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        temp_card[i][j]=0;
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=2; j<13; j++)
                    {
                        hand_player1[i][j]=shared_card[i][j-2];
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=2; j<13; j++)
                    {
                        hand_player2[i][j]=shared_card[i][j-2];
                    }
                }
                int hand_player1_temp[14],hand_player2_temp[14];
                int k=0;
                for(i=0; i<13; i++)
                {
                    for(j=0; j<5; j++)
                    {
                        if(hand_player1[j][i]!=0)
                        {
                            hand_player1_temp[k]=hand_player1[j][i];
                            k++;
                        }
                    }
                }
                k=0;
                for(i=0; i<13; i++)
                {
                    for(j=0; j<5; j++)
                    {
                        if(hand_player2[j][i]!=0)
                        {
                            hand_player2_temp[k]=hand_player2[j][i];
                            k++;
                        }
                    }
                }
                bubblesort(hand_player1_temp);
                bubblesort(hand_player2_temp);
                printf("\n\n");

                printf("玩家手牌加公牌(已排序):\n");


                for(i=0; i<14; i++)
                {
                    printf("%c",hand_player1_temp[i]);
                    if(i!=0&&i%2==1)
                        printf(" ");
                }
                printf("\n\n");

                printf("對手手牌加公牌(已排序):\n");
                for(i=0; i<14; i++)
                {
                    printf("%c",hand_player2_temp[i]);
                    if(i!=0&&i%2==1)
                        printf(" ");
                }

                printf("\n\n");
                int a,b;
                printf("玩家:");
                a=deal_card(hand_player1_temp);
                printf("對手:");
                b=deal_card(hand_player2_temp);

                if(a<b)
                {
                    printf("對手 win!!\n");
                }
                else if(a>b)
                {
                    printf("玩家 win!!\n");
                }
                else if(a==b)
                {
                    printf("平手\n");
                }
                system("pause");

                printf("\n\n");
                printf("***************************************");
                printf("\n\n");

                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        hand_player1[i][j]=0;
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        hand_player2[i][j]=0;
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        shared_card[i][j]=0;
                    }
                }
                for(i=0; i<5; i++)
                {
                    for(j=0; j<13; j++)
                    {
                        temp_card[i][j]=0;
                    }
                }

            }

        }
        printf("==SEE YOU NEXT TIME==\n\n");
        break;
    }
}


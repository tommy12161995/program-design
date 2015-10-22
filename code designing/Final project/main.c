#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
int game_start();
void shuffle();
void bubblesort();
int card_type();
int main()
{
    srand(time(NULL));
    char poke[2][52]= {{'A','2','3','4','5','6','7','8','9','T','J','Q','K','A','2','3','4','5','6','7','8','9','T','J','Q','K','A','2','3','4','5','6','7','8','9','T','J','Q','K','A','2','3','4','5','6','7','8','9','T','J','Q','K'},
        {'C','C','C','C','C','C','C','C','C','C','C','C','C','D','D','D','D','D','D','D','D','D','D','D','D','D','H','H','H','H','H','H','H','H','H','H','H','H','H','S','S','S','S','S','S','S','S','S','S','S','S','S'}
    };
    int flag_player1=0,flag_computer=0,flag_draw=0,flag=1;
    shuffle(poke);
    int i = 0;
    int a=game_start(flag);
    if(a == FALSE)
        return 0;
    while(a == TRUE) {
        printf("Player1:");
        printf("%c%c %c%c\n",poke[0][i],poke[1][i],poke[0][i+1],poke[1][i+1]);
        printf("Computer:");
        printf("%c%c %c%c\n",poke[0][i+2],poke[1][i+2],poke[0][i+3],poke[1][i+3]);
        printf("Community card:");
        printf("%c%c %c%c %c%c %c%c %c%c\n",poke[0][i+4],poke[1][i+4],poke[0][i+5],poke[1][i+5],poke[0][i+6],poke[1][i+6],poke[0][i+7],poke[1][i+7],poke[0][i+8],poke[1][i+8]);
        printf("---------------------\n");
        char player1[14]= {poke[0][i],poke[1][i],poke[0][i+1],poke[1][i+1],poke[0][i+4],poke[1][i+4],poke[0][i+5],poke[1][i+5],poke[0][i+6],poke[1][i+6],poke[0][i+7],poke[1][i+7],poke[0][i+8],poke[1][i+8]};
        char computer[14]= {poke[0][i+2],poke[1][i+2],poke[0][i+3],poke[1][i+3],poke[0][i+4],poke[1][i+4],poke[0][i+5],poke[1][i+5],poke[0][i+6],poke[1][i+6],poke[0][i+7],poke[1][i+7],poke[0][i+8],poke[1][i+8]};
        printf("Player1:");
        bubblesort(player1,14);
        printf("Computer:");
        bubblesort(computer,14);
        printf("---------------------\n");
        int b,c;
        b=card_type(player1);
        c=card_type(computer);
        if(b<c) {
            printf("Computer win!!\n");
            flag_computer++;
        } else if(b>c) {
            printf("Player1 win!!\n");
            flag_player1++;
        } else if(b==c) {
            printf("Draw.....\n");
            flag_draw++;
        }
        printf("---------------------\n");
        printf("Player1 wins:%d\n",flag_player1);
        printf("Computer wins:%d\n",flag_computer);
        printf("Draw:%d\n",flag_draw);
        i+=9;
        char poke_temp[104]= {'0'};
        int j,k=0;
        for(j=0; j<i; j++) {
            poke_temp[k]=poke[0][j];
            poke_temp[k+1]=poke[1][j];
            k+=2;
        }
        printf("Used:\n");
        bubblesort(poke_temp,i*2);
        printf("\n");
        if(i>=45) {
            i=0;
            printf("reshuffle.....\n");
            shuffle(poke);
        }
        flag++;
        a=game_start(flag);
    }
    return 0;
}
int game_start(int a)
{
    char response[100];
    if(a==1) {
        printf("Welcome here\n");
        printf("\n");
        printf("Do you want to play a game?\n");
        printf("1.Yes 2.No\n");
        while(1) {
            fgets(response,100,stdin);
            if(response[0] == '1' && strlen(response)==2) {
                printf("OK! Let's start!\n");
                return TRUE;
                break;
            } else if(response[0] == '2' && strlen(response)==2) {
                printf("It's a pity.....\n");
                return FALSE;
                break;
            } else
                printf("Are you kidding me? Choose again.\n");
        }
    } else {
        printf("Do you want to play again?\n");
        printf("1.Yes 2.No\n");
        while(1) {
            fgets(response,100,stdin);
            if(response[0] == '1' && strlen(response)==2) {
                printf("OK! Let's start!\n");
                return TRUE;
                break;
            } else if(response[0] == '2' && strlen(response)==2) {
                printf("It's a pity.....\n");
                return FALSE;
                break;
            } else
                printf("Are you kidding me? Choose again.\n");
        }
    }
}
void shuffle(char poke[][52])
{
    int i,a;
    char temp1,temp2;
    for(i=0; i<52; i++) {
        a=rand()%52;
        temp1=poke[0][i];
        poke[0][i]=poke[0][a];
        poke[0][a]=temp1;
        temp2=poke[1][i];
        poke[1][i]=poke[1][a];
        poke[1][a]=temp2;
    }
}
void bubblesort(char a[],int n)
{
    int i,j=0,k=0,b[60]= {0},c[60]= {0};
    for(i=0; i<n; i++) {
        if(i%2==0) {
            switch(a[i]) {
            case 'A':
                b[j]=1;
                break;
            case '2':
                b[j]=2;
                break;
            case '3':
                b[j]=3;
                break;
            case '4':
                b[j]=4;
                break;
            case '5':
                b[j]=5;
                break;
            case '6':
                b[j]=6;
                break;
            case '7':
                b[j]=7;
                break;
            case '8':
                b[j]=8;
                break;
            case '9':
                b[j]=9;
                break;
            case 'T':
                b[j]=10;
                break;
            case 'J':
                b[j]=11;
                break;
            case 'Q':
                b[j]=12;
                break;
            case 'K':
                b[j]=13;
                break;
            }
            j++;
        } else if(i%2==1) {
            switch(a[i]) {
            case 'C':
                c[k]=1;
                break;
            case 'D':
                c[k]=2;
                break;
            case 'H':
                c[k]=3;
                break;
            case 'S':
                c[k]=4;
                break;
            }
            k++;
        }
    }
    int temp1,temp2;
    int m,l;
    for(m=0; m<n/2-1; m++) {
        for(l=0; l<n/2-(m+1); l++) {
            if(b[l]>b[l+1]) {
                temp1=b[l];
                b[l]=b[l+1];
                b[l+1]=temp1;
                temp2=c[l];
                c[l]=c[l+1];
                c[l+1]=temp2;
            }
        }
    }
    for(m=0; m<n/2-1; m++) {
        for(i=0; i<n/2-(m+1); i++) {
            if(b[i]==b[i+1]) {
                if(c[i]>c[i+1]) {
                    temp2=c[i];
                    c[i]=c[i+1];
                    c[i+1]=temp2;
                }
            }
        }
    }
    j=0;
    k=1;
    for(i=0; i<n/2; i++) {
        switch(b[i]) {
        case 1:
            a[j]='A';
            break;
        case 2:
            a[j]='2';
            break;
        case 3:
            a[j]='3';
            break;
        case 4:
            a[j]='4';
            break;
        case 5:
            a[j]='5';
            break;
        case 6:
            a[j]='6';
            break;
        case 7:
            a[j]='7';
            break;
        case 8:
            a[j]='8';
            break;
        case 9:
            a[j]='9';
            break;
        case 10:
            a[j]='T';
            break;
        case 11:
            a[j]='J';
            break;
        case 12:
            a[j]='Q';
            break;
        case 13:
            a[j]='K';
            break;
        }
        j+=2;
        switch(c[i]) {
        case 1:
            a[k]='C';
            break;
        case 2:
            a[k]='D';
            break;
        case 3:
            a[k]='H';
            break;
        case 4:
            a[k]='S';
            break;
        }
        k+=2;
        printf("%c%c ",a[j-2],a[k-2]);
    }
    printf("(¤w±Æ§Ç)\n");
}
char b_c(int i)
{
    char number[14] = {' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    return number[i];
}
char c_c(int i)
{
    char suit[5] = {' ', 'C', 'D', 'H', 'S'};
    return suit[i];
}
int card_type(char a[])
{
    int i,j=0,k=0,b[7],c[7];
    for(i=0; i<14; i++) {
        if(i%2==0) {
            switch(a[i]) {
            case 'A':
                b[j]=1;
                break;
            case '2':
                b[j]=2;
                break;
            case '3':
                b[j]=3;
                break;
            case '4':
                b[j]=4;
                break;
            case '5':
                b[j]=5;
                break;
            case '6':
                b[j]=6;
                break;
            case '7':
                b[j]=7;
                break;
            case '8':
                b[j]=8;
                break;
            case '9':
                b[j]=9;
                break;
            case 'T':
                b[j]=10;
                break;
            case 'J':
                b[j]=11;
                break;
            case 'Q':
                b[j]=12;
                break;
            case 'K':
                b[j]=13;
                break;
            }
            j++;
        } else if(i%2==1) {
            switch(a[i]) {
            case 'C':
                c[k]=1;
                break;
            case 'D':
                c[k]=2;
                break;
            case 'H':
                c[k]=3;
                break;
            case 'S':
                c[k]=4;
                break;
            }
            k++;
        }
    }
    int n,color[5]= {0},number[5]= {0},flag=0;
    /*Straight flush*/
    for(i=0; i<3; i++) {
        flag=0;
        color[0]=c[i];
        number[0]=b[i];
        for(j=i+1; j<7; j++) {
            if(color[0]==c[j]) {
                flag++;
                color[flag]=c[j];
                number[flag]=b[j];
                if(flag==4)
                    break;
            }
        }
        if(flag==4) {
            if(number[0]+1==number[1]&&number[1]+1==number[2]&&number[2]+1==number[3]&&number[3]+1==number[4]) {
                for(j=0; j<=4; j++) {
                    printf("%c%c ",b_c(number[j]),c_c(color[j]));
                }
                printf("Straight flush\n");
                return 9;
            } else if(number[0]==1&&number[1]==10&&number[2]==11&&number[3]==12&&number[4]==13) {
                printf("%c%c %c%c %c%c %c%c %c%c ",b_c(number[1]),c_c(color[1]),b_c(number[2]),c_c(color[2]),b_c(number[3]),c_c(color[3]),b_c(number[4]),c_c(color[4]),b_c(number[0]),c_c(color[0]));
                printf("Straight flush\n");
                return 9;
            }
            break;
        }
    }
    n=4;
    while(n--) { /*Four of a kind*/
        if(b[n]==b[n+1]&&b[n+1]==b[n+2]&&b[n+2]==b[n+3]) {
            if(n==3) {
                printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[3]),c_c(c[3]),b_c(b[4]),c_c(c[4]),b_c(b[5]),c_c(c[5]),b_c(b[6]),c_c(c[6]),b_c(b[0]),c_c(c[0]));
                printf("Four of a kind\n");
                return 8;
                break;
            } else {
                for(i=n; i<=n+4; i++) {
                    printf("%c%c ",b_c(b[n]),c_c(c[n]));
                }
                printf("Four of a kind\n");
                return 8;
                break;
            }
        } else
            continue;
    }
    for(i=0; i<=4; i++) { /*Full House*/
        if(b[i]==b[i+1]&&b[i+1]==b[i+2]) {
            for(j=i+3; j<=5; j++) {
                if(b[j]==b[j+1]) {
                    printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[i+2]),c_c(c[i+2]),b_c(b[j]),c_c(c[j]),b_c(b[j+1]),c_c(c[j+1]));
                    printf("Full House\n");
                    return 7;
                    break;
                }
            }
            for(j=i-1; j>=1; j--) {
                if(b[j]==b[j-1]) {
                    printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[i+2]),c_c(c[i+2]),b_c(b[j]),c_c(c[j]),b_c(b[j-1]),c_c(c[j-1]));
                    printf("Full House\n");
                    return 7;
                    break;
                }
            }
        }
    }
    /*Flush*/
    for(i=0; i<3; i++) {
        flag=0;
        color[0]=c[i];
        number[0]=b[i];
        for(j=i+1; j<7; j++) {
            if(color[0]==c[j]) {
                flag++;
                color[flag]=c[j];
                number[flag]=b[j];
            }
            if(flag==4)
                break;
        }
        if(flag==4) {
            for(j=0; j<=4; j++) {
                printf("%c%c ",b_c(number[j]),c_c(color[j]));
            }
            printf("Flush\n");
            return 6;
        }
    }
    /*Straight*/
    for(i=0; i<3; i++) {
        flag=0;
        number[0]=b[i];
        color[0]=c[i];
        for(j=i+1; j<7; j++) {
            if(b[i]+1+flag==b[j]) {
                flag++;
                number[flag]=b[j];
                color[flag]=c[j];
            }
            if(flag==4)
                break;
        }
        if(flag==4) {
            for(j=0; j<=4; j++) {
                printf("%c%c ",b_c(number[j]),c_c(color[j]));
            }
            printf("Straight\n");
            return 5;
        } else if(number[0]==1&&number[1]==10&&number[2]==11&&number[3]==12&&number[4]==13) {
            printf("%c%c %c%c %c%c %c%c %c%c ",b_c(number[1]),c_c(color[1]),b_c(number[2]),c_c(color[2]),b_c(number[3]),c_c(color[3]),b_c(number[4]),c_c(color[4]),b_c(number[0]),c_c(color[0]));
            printf("Straight\n");
            return 5;
        }
        break;
    }
    for(i=0; i<=4; i++) { /*Three of a kind*/
        if(b[i]==b[i+1]&&b[i+1]==b[i+2]) {
            if(i<=2) {
                printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[i+2]),c_c(c[i+2]),b_c(b[i+3]),c_c(c[i+3]),b_c(b[i+4]),c_c(c[i+4]));
                printf("Three of a kind\n");
                return 4;
                break;
            } else {
                printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[i+2]),c_c(c[i+2]),b_c(b[i-1]),c_c(c[i-1]),b_c(b[i-2]),c_c(c[i-2]));
                printf("Three of a kind\n");
                return 4;
                break;
            }
        }
    }
    for(i=0; i<=3; i++) { /*Two pairs*/
        if(b[i]==b[i+1]) {
            for(j=i+2; j<=5; j++) {
                if(b[j]==b[j+1]) {
                    if(j==5&&i==3) {
                        printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[j]),c_c(c[j]),b_c(b[j+1]),c_c(c[j+1]),b_c(b[0]),c_c(c[0]));
                        printf("Two pairs\n");
                        return 3;
                        break;
                    } else if(j==5&&i!=3) {
                        printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[j]),c_c(c[j]),b_c(b[j+1]),c_c(c[j+1]),b_c(b[i+2]),c_c(c[i+2]));
                        printf("Two pairs\n");
                        return 3;
                        break;
                    } else {
                        printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[j]),c_c(c[j]),b_c(b[j+1]),c_c(c[j+1]),b_c(b[j+2]),c_c(c[j+2]));
                        printf("Two pairs\n");
                        return 3;
                        break;
                    }
                }
            }
        }
    }
    for(i=0; i<=5; i++) { /*One pair*/
        if(b[i]==b[i+1]) {
            if(i>=3) {
                printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[0]),c_c(c[0]),b_c(b[1]),c_c(c[1]),b_c(b[2]),c_c(c[2]));
                printf("One pair\n");
                return 2;
                break;
            } else {
                printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[i]),c_c(c[i]),b_c(b[i+1]),c_c(c[i+1]),b_c(b[i+2]),c_c(c[i+2]),b_c(b[i+3]),c_c(c[i+3]),b_c(b[i+4]),c_c(c[i+4]));
                printf("One pair\n");
                return 2;
                break;
            }
        }
    }
    /*High Card*/
    printf("%c%c %c%c %c%c %c%c %c%c ",b_c(b[6]),c_c(c[6]),b_c(b[5]),c_c(c[5]),b_c(b[4]),c_c(c[4]),b_c(b[3]),c_c(c[3]),b_c(b[2]),c_c(c[2]));
    printf("High Card\n");
    return 1;
}

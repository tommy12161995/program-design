#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    while(scanf("%d", &test) != EOF) {
        while(test--) {
            int input[6];
            scanf("%d, %d, %d, %d, %d, %d", &input[0], &input[1], &input[2], &input[3],&input[4], &input[5]);

            int combination = 0, min = 6, a, b;
            for(int i = 0; i <= 4 ; i++) {
                for(int j = i + 1; j <= 5; j++) {
                    if(input[i] + input[j] <= 6) {
                        combination = i + (j - i - 1);
                        if(min > combination) {
                            min = combination;
                            a = input[i];
                            b = input[j];
                        }
                    }
                }
            }
            printf("The best combination is %d, %d, Complaint=%d\n", a, b, min);
        }
    }

    return 0;
}

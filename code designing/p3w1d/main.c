#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
    int right;
} part;

int cmp(const void *a, const void *b);

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            int num;
            scanf("%d", &num);
            part line[num];
            for (int i = 0; i < num; i++)
                scanf("%d %d", &line[i].left, &line[i].right);
            qsort(line, num, sizeof(part), cmp);
            int sum_left = line[0].left, sum_right = line[0].right, sum = 0;
            if (num == 1)
                sum = sum_right - sum_left;
            for (int i = 1; i < num; i++) {
                if (sum_left <= line[i].left && line[i].left <= sum_right &&
                    line[i].right >= sum_right) {
                    sum_right = line[i].right;

                }

                else if (line[i].left > sum_right) {
                    sum += sum_right - sum_left;
                    sum_left = line[i].left;
                    sum_right = line[i].right;
                }
                if (i == num - 1) {
                    if (sum_right < line[i].right)
                        sum_right = line[i].right;
                    sum += sum_right - sum_left;
                }
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}

int cmp(const void *a, const void *b)
{
    if (((part *)a)->left - ((part *)b)->left != 0)
        return ((part *)a)->left - ((part *)b)->left;
    else
        return ((part *)a)->right - ((part *)b)->right;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int find_max(long long int a,long long int b) {
    if (a > b)
        return a;
    else
        return b;
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        long long int array[n][n];
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%lld", &array[i][j]);
            }
        }
        long long int ans[n][n];
        memset(ans, -1, sizeof(ans));
        ans[0][0] = array[0][0];
        for (i = 1; i < n; i++)
            ans[i][0] = ans[i - 1][0] + array[i][0];
        for (j = 1; j < n; j++)
            ans[0][j] = ans[0][j-1] + array[0][j];
        for (i = 1; i < n; i++)
            for ( j = 1; j < n; j++)
                ans[i][j] = find_max(ans[i-1][j], ans[i][j-1]) + array[i][j];

        printf("%lld\n", ans[n - 1][n - 1]);
    }
    return 0;
}

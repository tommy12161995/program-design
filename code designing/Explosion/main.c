#include <stdio.h>

int get_damage(int ,int, int, int, int, int, int);
int total = 0;

int main()
{
    int X, Y, N, x, y, w, h;
    while(scanf("%d %d %d %d %d %d %d", &X, &Y, &N, &x, &y, &w, &h) != EOF) {
        printf("%d\n", get_damage(X, Y, N, x, y, w, h));
        total = 0;
    }
    return 0;
}

int get_damage(int X, int Y, int N, int x, int y, int w, int h)
{
    if(N >= 2) {
        int a, b;
        for(b = Y + N / 2; b >= Y - N / 2; b--)
            for(a = X - N / 2; a <= X + N / 2; a++)
                if((a >= x && a <= x + w) && (b >= y && b <= y + h)) //在範圍內的直接加起來
                    total += N;
        get_damage(X + N * 3 / 4, Y, N / 2, x, y, w, h);
        get_damage(X - N * 3 / 4, Y, N / 2, x, y, w, h);
        get_damage(X, Y + N * 3 / 4, N / 2, x, y, w, h);
        get_damage(X, Y - N * 3 / 4, N / 2, x, y, w, h);
    }
    return total;
}

#include <stdio.h>
#include <stdlib.h>
/*
http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=949&mosmsg=Submission+received+with+ID+14430904
*/

void read_line(char, int);

int main()
{
    int line_count;
    while(scanf("%d", &line_count)!= EOF)
    {
        int answer[127];/*A-Z 65-90. a-z 97-122*/
        int i;
        for(i = 0; i < 127; i++)
        {
            answer[i] = 0;
        }
        while(line_count--)
        {
            char text[1000];
            for(i = 0; i < 1000; i++)
            {
                text[i] = '\0';
            }

            gets(text);/*Don't use scanf!!*/
            /*analysis*/
            for(i = 0; i < 1000; i++)
            {
                int ascii = text[i]; /*0 is space*/
                answer[ascii] = answer[ascii] + 1;
            }

            /*count the lower case with the upper case together*/
            for(i = 97; i <=122; i++)
            {
                answer[i - 32] = answer[i] + answer[i -32];
                answer[i] = 0;
            }

            /*for(i = 0; i < 127; i++)
            {
                if(answer[i] != 0)
                {
                    printf("%d %d\n", i, answer[i]);
                }
            }*/
        }
        int times;
        for(times = 1000; times >= 0; times--)/*check form 1000 to 0 occurrence*/
        {
            for(i = 65; i<= 90; i++)
            {
                if(times == answer[i] && answer[i] != 0)
                    printf("%c %d\n", i, answer[i]);
            }
        }
    }
    return 0;
}


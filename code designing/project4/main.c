#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double interval(double (*f)(double),char *from,char *to,char *t);

double user_funtion(double input);

int main()
{
    char input[100];
    while(fgets(input,100,stdin)!=NULL) {
        char *f,*from,*to,*t;
        f=strtok(input,",");
        from=strtok(NULL,",");
        to=strtok(NULL,",");
        t=strtok(NULL,"\n");
        //printf("%s %s %s %s\n",f,from,to,t);
        char *math[4]= {"sin","cos","tan","user"};
        if(strcmp(f,math[0])==0)
            printf("%f\n",interval(sin,from,to,t));
        else if(strcmp(f,math[1])==0)
            printf("%f\n",interval(cos,from,to,t));
        else if(strcmp(f,math[2])==0)
            printf("%f\n",interval(tan,from,to,t));
        else if(strcmp(f,math[3])==0)
            printf("%f\n",interval(user_funtion,from,to,t));
        else
            printf("Not supported.\n");
    }
    return 0;
}
double interval(double (*f)(double),char *from,char *to,char *t)
{
    float output=0;
    for(double i=atof(from); i<atof(to); i+=atof(t)) {
        output+=f(i)*atof(t);
    }
    return output;
}

double user_funtion(double input)
{
    double answer = input*input;
    return answer;
}

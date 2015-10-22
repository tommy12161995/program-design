#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int test;
    scanf("%d",&test);
        getchar();
        while(test--) {
            char input[20000] = {'\0'};
            char temp[20000] = {'\0'};
            fgets(input, 20000, stdin);
            input[strlen(input) - 1] = '\0';
            int cnt=0;
            //printf("frist: %s\n",input);
            for(int i = 0; i <strlen(input); i++) {
                int len = strlen(input);
                cnt = i+1;
                if(input[i] == 'a') {
                    for(int j=0; j<=i; j++) {
                        temp[j] = input[j];
                    }
                    //printf("len: %d\n",strlen(input));
                    for(int j=len; j>i+1; j--) {
                        temp[cnt++] = input[j-1];
                    }
                    memset(input,'\0',sizeof(input));
                    memcpy(input,temp,sizeof(char)*strlen(temp));
                    memset(temp,'\0',sizeof(temp));
                    //printf("%s\n",input);
                }if(input[i]=='b') {
                    memcpy(temp,input,sizeof(char)*strlen(input));
                    for(int j=strlen(input); j<2*len-i; j++) {
                        temp[j] = input[cnt++];
                    }
                    memset(input,'\0',sizeof(input));
                    memcpy(input,temp,sizeof(char)*strlen(temp));
                    memset(temp,'\0',sizeof(temp));
                }if(input[i]=='c') {
                    for(int j=0; j<=i; j++) {
                        temp[j] = input[j];
                    }
                    for(int j=i+1; j<(len+2); j++) {
                        temp[j] = input[j+2];
                    }
                    memset(input,'\0',sizeof(input));
                    memcpy(input,temp,sizeof(char)*strlen(temp));
                    memset(temp,'\0',sizeof(temp));
                }
            }
            printf("%s\n",input);
    }
    return 0;
}

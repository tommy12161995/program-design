#include <stdio.h>
#include <stdlib.h>
#include<string.h>

power(int a, int b){
    int i;
    for(i=0; i<b; i++){
        a*=2;
    }
    return a;
}

int main(){
    int n, len, digits, temp;
    long long int input, sum;
    int i, j;
    int num[32];

    while(EOF!=scanf("%d", &n)){
        if(n==0) break;

        sum=0;
        while(n--){
            scanf("%lld", &input);

            for(i=0; input!=0; i++){
                num[i]=input%10;
                input/=10;
            }
            digits=i;
            temp=0;
            for(i=0; i<digits; i++){
                temp+=power(num[i], i);
            }
            sum+=temp;

        }

        printf("%lld\n", sum);
    }
    return 0;
}

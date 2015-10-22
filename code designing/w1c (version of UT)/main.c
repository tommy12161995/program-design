#include <stdio.h>
#include <stdlib.h>

int main(){
    int p, q, temp;
    int f;

    while(EOF!=scanf("%d %d", &p, &q)){
        if(q==0) break;

        if(p==q){
            f=1;
            printf("%d\n", f);
        }
        else{
            temp=p;
            f=0;

            while(1){
                p=(p*10)%q;
                f++;
                if(temp==p) break;
            }

            printf("%d\n", f);
        }
    }
    return 0;
}

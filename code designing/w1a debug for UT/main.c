#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    while(scanf("%d", &n)!=EOF){
        while(n--){
        int a, b, c, d, i, j, k, N=3;
        int temp1[3]={0}, temp2[30]={0}, num[30]= {0};
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a == 0)
            break;
        temp1[0]=temp2[0]=c;
        temp1[1]=temp2[1]=b;
        temp1[2]=temp2[2]=a;

        for(k=1; k<d; k++){
            for(i=0; i<3; i++){
                for(j=0; j<N; j++){
                    num[i+j]+=temp1[i]*temp2[j];
                }
                }

                 N+=2;

                for(j=0; j<N; j++){
                    temp2[j]=num[j];
                    num[j]=0;
            }
        }

        for(i=N-1; i>=0; i--){
            if(i == 0)
                printf("%d\n", temp2[i]);
            else
                printf("%d ", temp2[i]);
        }
    }
    }


    return 0;
}

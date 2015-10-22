#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;


    while(scanf("%d", &n)!=EOF){
        int i, j;
        int a[55], b[55];
        int x, y, A, temp;
        while(n--){

        scanf("%d", &m);
        for(i=0; i<m; i++){
            scanf("%d %d", &(a[i]), &(b[i]));
        }

        A=temp=0;

        for(i=0; i<(m-1); i++){
            for(j=(i+1); j<m; j++){
                if(a[i]>a[j]) x=a[i]-a[j];
                else x=a[j]-a[i];

                if(b[i]>b[j]) y=b[i]-b[j];
                else y=b[j]-b[i];

                temp=x*y;
                if(temp>A) A=temp;

            }
        }

        printf("%d\n", A);
    }

    }

    return 0;
}

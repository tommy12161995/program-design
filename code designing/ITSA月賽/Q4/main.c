#include <stdio.h>
#include <stdlib.h>
char XP[44][44];
int XD(int c,int d,int n){
	if(c==n-1&&d==2*n-2) return 0;
    if(XP[c+1][d]=='0'){
         XP[c+1][d]='*';
         XD(c+1,d,n);
    }
    if(XP[c-1][d]=='0'){
        XP[c-1][d]='#';
        XD(c-1,d,n);
    }
    if(XP[c][d-2]=='0'){
         XP[c][d-2]='#';
         XD(c,d-2,n);
    }
    if(XP[c][d+2]=='0'){
        XP[c][d+2]='#';
        XD(c,d+2,n);
    }
}
int main(){
	int n,i,j,m;
	while(scanf("%d[\n]",&n)!=EOF){
		memset(XP,' ',sizeof(XP));
		for(i=0;i<n;i++){
			gets(XP[i]);
		}
		m=XD(1,2,n);
		for(i=0;i<n;i++){
			for(j=0;j<2*n-1;j++){
                printf("%c",XP[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}

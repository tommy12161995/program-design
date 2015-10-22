#include <stdio.h>
#include <stdlib.h>
int XP[1000][1000];
long long int XD(int c,int d){
	if(c>0 && d>0 && c<=a && d<=b){
		XP[c][d]=0;
		if(XP[c-1][d]==1) XD(c-1,d);
		if(XP[c][d-1]==1) XD(c,d-1);
		if(XP[c][d+1]==1) XD(c,d+1);
		if(XP[c+1][d]==1) XD(c+1,d);
	}
}
int main()
{
	long long int n,i,j,k;
	while(scanf("%lld",&n)!=EOF){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
                scanf("%d",XP[i][j]);
			}
		}
		for(i=1;i<=a;i++){
			for(j=1;j<=b;j++){
				if(XP[i][j]=='@')
					XP[i][j]=1;
				else
					XP[i][j]=0;
			}
		}
		k=0;
		for(i=1;i<=a;i++){
			for(j=1;j<=b;j++){
				if(XP[i][j]==1)
				{
					XD(i,j);
					k=k+1;
				}
			}
		}
		printf("%lld\n",k);
	}
    return 0;
}

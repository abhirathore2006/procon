#include <stdio.h>
#define MM 3
#define M 3
int m[MM*MM][MM*MM],z[MM*MM+1];
int grid(int I,int J){
	int i,j,x,y;
	i=I;//for(i=0;i<M*M;i++){
		for(j=1;j<=M*M;j++)z[j]=0;
		for(j=0;j<M*M;j++)if(m[i][j]&&++z[m[i][j]]>1)return 0;
	//}
	j=J;//for(j=0;j<M*M;j++){
		for(i=1;i<=M*M;i++)z[i]=0;
		for(i=0;i<M*M;i++)if(m[i][j]&&++z[m[i][j]]>1)return 0;
	//}
	i=I/M+J/M*M;
	//for(i=0;i<M*M;i++){
		for(j=1;j<=M*M;j++)z[j]=0;
		for(j=0;j<M*M;j++)if(m[x=i%M*M+j/M][y=i/M*M+j%M]&&++z[m[x][y]]>1)return 0;
	//}
	return 1;
}
int dfs(int n){
	int i,j,k;
	if(n==M*M*M*M)return 1;
	i=n/(M*M),j=n%(M*M);
	if(m[i][j])return dfs(n+1);
	for(k=1;k<=M*M;k++){
		m[i][j]=k;
		if(grid(i,j)&&dfs(n+1))return 1;
	}
	m[i][j]=0;
	return 0;
}
int main(){
	int i,j,n,c;
	scanf("%d",&n);for(;getchar()!='\n';);
	for(;n--;){
		for(i=0;i<M*M;i++){
			for(j=0;j<M*M;j++){
				m[i][j]=getchar()-'0';
			}
			for(;(c=getchar())!='\n'&&~c;);
		}
		if(!dfs(0))return 1;
		for(i=0;i<M*M;i++)for(j=0;j<M*M;j++){
			printf(j==M*M-1?"%d\n":"%d",m[i][j]);
		}
	}
}
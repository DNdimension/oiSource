#include <cstdio>
const int N=1001;
int a,b,h,ans,f[N][N];
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int min(int a,int b) {
	if(a<b) return a;
	return b;
}
int main() {
	scanf("%d%d%d",&h,&a,&b);
	for(int i=1;i<=h;i++) {
		int i1=max(0,i-b);
		int i2=max(0,i-a);
		f[i][0]=min(f[i1][0],f[i2][a-1])+1;
		for(int j=1;j<=1000;j++) {
			int i3=max(i-b-j,0);
			int i4=max(i-a-j,0);
			f[i][j]=min(f[i3][j-1],f[i4][a+j-1])+1;
		}
	}
	ans=f[h][0];
	for(int i=1;i<=1000;i++) ans=min(ans,f[h][0]);
	printf("%d",ans);
	return 0;
}
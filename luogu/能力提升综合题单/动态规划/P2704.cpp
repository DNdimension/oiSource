#include <iostream>
using namespace std;
constexpr int N=102,M=60;
int f[N][M][M],map[N],n,m;
int k[M],v[M],cnt,ans;
char ch;
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>ch;
			if(ch=='H') map[i]|=1<<m-j;
		}
	}
	for(int i=1,val,j;i<(1<<m);i++) {
		j=i,val=0;
		for(int lbi,lst=j&-j;j;val++) {
			lbi=j&-j;
			if(lst>lbi) break;
			j-=lbi;
			lst=lbi<<3;
		}
		if(!j) {
			cnt++;
			k[cnt]=i;
			v[cnt]=val;
		}
	}
	for(int i=0;i<=cnt;i++) {
		if(map[1]&k[i]) continue;  
		f[1][i][0]=v[i];
	}
	for(int i=0;i<=cnt;i++) {
		for(int j=0;j<=cnt;j++) {
			if(map[2]&k[i]||k[i]&k[j]) continue;
			f[2][i][j]=max(f[2][i][j],v[i]+f[1][j][0]);
		}
	}
	for(int p=3;p<=n;p++) {	
		for(int i=0;i<=cnt;i++) {
			for(int j=0;j<=cnt;j++) {
				for(int l=0;l<=cnt;l++) {
					if(map[p]&k[i]||k[i]&k[j]||k[i]&k[l]||k[j]&k[l]) continue;
					f[p][i][j]=max(f[p][i][j],v[i]+f[p-1][j][l]);
				}
			}
		}
	}
	for(int i=0;i<=cnt;i++) {
		for(int j=0;j<=cnt;j++) {
				ans=max(ans,f[n][i][j]);
		}
	}
	cout<<ans;
	return 0;
}
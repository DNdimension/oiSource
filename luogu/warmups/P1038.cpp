#include <iostream>
#include <bitset>
#define int long long int
#define N 101
using namespace std;
int n,p,tc;
int W[N][N],To[N][N],d[N],C[N],U[N],t[N*N];
bitset<N> f;
inline void solve() {
	int i=0;
	while(tc>i) {
		i++;
		if(!f[t[i]]) {
			for(int j=1;j<=d[t[i]];j++) {
				if(f[To[t[i]][j]]) continue;
				f[t[i]]=1;
				t[++tc]=To[t[i]][j];
				if(C[t[i]]>0) C[To[t[i]][j]]+=C[t[i]]*W[t[i]][j];
			}
		}
	}
	return;
}
signed main() {
	cin>>n>>p;
	for(int i=1;i<=n;i++) {
		cin>>C[i]>>U[i];
		if(C[i]) t[++tc]=i;
		else C[i]-=U[i];
	}
	for(int i=1,j,k,m;i<=p;i++) {
		cin>>j>>k>>m;
		d[j]++;
		d[k]++;
		To[j][d[j]]=k;
		To[k][d[k]]=j;
		W[k][d[k]]=W[j][d[j]]=m;
	}
	solve();
	f[0]=1;
	for(int i=1;i<=n;i++) if(!f[i]&&C[i]>0) f[0]=0,cout<<i<<' '<<C[i]<<'\n';
	if(f[0]) cout<<"NULL";
	return 0;
}

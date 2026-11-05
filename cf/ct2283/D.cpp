#include <iostream>
using namespace std;
constexpr int N=3e5+2;
int T,n,gc,hd[N],nx[N<<1],to[N<<1],f[N];
void bld(int u,int v) {
	nx[++gc]=hd[u];
	hd[u]=gc,to[gc]=v;
	nx[++gc]=hd[v];
	hd[v]=gc,to[gc]=u;
}
void dfs(int u,int fa) {
	f[u]=gc;
	for(int j=hd[u],v;~j;j=nx[j]) {
		v=to[j];
		if(v==fa) continue;
		dfs(v,u);
	}
}
bool ck(int u,int k) {
	gc=0;
	for(int j=hd[u],v;~j;j=nx[j]) {
		v=to[j];
		dfs(v,u);
		gc++;
	}
	for(int i=1;i<=n;i++) {
		if(k-i<1||k-i>n||i==u) continue;
		if(f[i]!=f[k-i]) return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		gc=0;
		cin>>n;
		for(int i=1;i<=n;i++) hd[i]=-1;
		for(int i=1,u,v;i<n;i++) {
			cin>>u>>v;
			bld(u,v);
		}
		if(n%2==0) cout<<n+1;
		else if(ck(1,n+2)) cout<<n+2;
		else if(ck(n,n)) cout<<n;
		else cout<<n+1;
		cout<<'\n';
	}
	return 0;
}
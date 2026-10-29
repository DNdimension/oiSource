#include <iostream>
using namespace std;
constexpr int N=5e5+2;
int T,n,ans,m,dep[N],gc,nx[N<<1],to[N<<1],hd[N];
void bld(int u,int v) {
	nx[++gc]=hd[u];
	hd[u]=gc,to[gc]=v;
	nx[++gc]=hd[v];
	hd[v]=gc,to[gc]=u;
}
void dfs(int u,int fa) {
	dep[u]=dep[fa]+1;
	if(u==1) {
		ans=dep[1];
		dep[1]=-1e9;
		return;
	}
	for(int j=hd[u],v;~j;j=nx[j]) {
		v=to[j];
		if(v==fa) continue;
		dfs(v,u);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		gc=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) hd[i]=-1,dep[i]=0;
		for(int i=1,u,v;i<n;i++) {
			cin>>u>>v;
			bld(u,v);
		}
		dep[n]=-1;
		dfs(n,n);
		for(int i=1,x;i<=m;i++) {
			cin>>x;
			ans=max(ans,dep[x]+1);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
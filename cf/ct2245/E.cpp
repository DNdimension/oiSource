#include <iostream>
#include <bitset>
using namespace std;
constexpr int N=2e5+2;
int n,T,gc,ac,d[N],hd[N],nx[N<<1],to[N<<1];
long long ans;
bitset<N> vis;
void build(int u,int v) {
	nx[++gc]=hd[u];
	to[gc]=v,hd[u]=gc;
	nx[++gc]=hd[v];
	to[gc]=u, hd[v]=gc;
	d[u]++,d[v]++;
}
void dfs(int u) {
	vis[u]=1;
	for(int j=hd[u],v;~j;j=nx[j]) {
		v=to[j];
		if(d[v]&1) ans+=ac++;
		else if(!vis[v]) dfs(v);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		ans=gc=0;
		for(int i=1;i<=n;i++) hd[i]=-1,d[i]=vis[i]=0;
		for(int i=1,u,v;i<n;i++) {
			cin>>u>>v;
			build(u,v);
		}
		for(int i=1;i<=n;i++) {
			ac=0;
			if(~d[i]&1&&!vis[i]) dfs(i);
		}
		ac=0;
		for(int u=1;u<=n;u++) {
			if(~d[u]&1) continue;
			for(int j=hd[u],v;~j;j=nx[j]) {
				v=to[j];
				if(d[v]&1) ac++;
			}
		}
		cout<<ans+ac/2<<'\n';
	}
	
	return 0;
}
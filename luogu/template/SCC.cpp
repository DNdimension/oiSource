#include <iostream>
#include <bitset>
#include <stack>
#include <queue>
using namespace std;
constexpr int N=1e4+2,M=1e5+2;
int n,m,gc,dc,scc[N],low[N],ans[N],inS[N],dfn[N],d[N],w[N],hd[N],u0[M],v0[M],nx[M],to[M];
stack<int> S;
queue<int> Q;
bitset<N> adj[N];
void bld(int u,int v) {
	nx[++gc]=hd[u];
	hd[u]=gc,to[gc]=v;
}
void dfs(int u) {
	dfn[u]=low[u]=++dc,inS[u]=1;
	S.push(u);
	for(int j=hd[u];~j;j=nx[j]) {
		int v=to[j];
		if(!dfn[v]) {
			dfs(v);
			low[u]=min(low[u],low[v]);
		} else if(inS[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) {
		for(int v=S.top();v!=u;v=S.top()) {
			S.pop();
			w[u]+=w[v],scc[v]=u,inS[v]=0;
		}
		scc[u]=u,inS[u]=0;
		S.pop();
	}
}
void calc() {
	for(int u=1;u<=n;u++) if(!d[u]&&u==scc[u]) Q.push(u),ans[u]=w[u];
	while(!Q.empty()) {
		int u=Q.front();
		Q.pop();
		for(int j=hd[u],v;~j;j=nx[j]) {
			v=to[j];
			ans[v]=max(ans[v],ans[u]+w[v]);
			if(!--d[v]) Q.push(v);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) hd[i]=-1;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++) {
		cin>>u0[i]>>v0[i];
		bld(u0[i],v0[i]);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	gc=0;
	for(int i=1;i<=n;i++) hd[i]=-1;
	for(int i=1;i<=m;i++) {
		int u=scc[u0[i]],v=scc[v0[i]];
		if(u==v||adj[u][v]) continue;
		adj[u][v]=1,bld(u,v);
	}
	for(int i=1;i<=n;i++) {
		for(int j=hd[i];~j;j=nx[j]) d[to[j]]++;
	}
	calc();
	for(int i=1;i<=n;i++) ans[0]=max(ans[0],ans[i]);
	cout<<ans[0]<<'\n';
	return 0;
}
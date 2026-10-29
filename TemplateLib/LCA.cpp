#include <iostream>
using namespace std;
constexpr int N=5e5+2,LOGN=21;
int n,m,S,gc,dep[N],fa[N][LOGN+1],hd[N],nx[N<<1],to[N<<1];
void bld(int u,int v) {
	nx[++gc]=hd[u];
	hd[u]=gc, to[gc]=v;
	nx[++gc]=hd[v];
	hd[v]=gc, to[gc]=u;
}
void dfs(int u) {
	for(int j=1;j<=LOGN;j++) 
		if(~fa[u][j-1]) fa[u][j]=fa[fa[u][j-1]][j-1];
	for(int j=hd[u],v;~j;j=nx[j]) {
		v=to[j];
		if(v==fa[u][0]) continue;
		dep[v]=dep[u]+1,fa[v][0]=u;
		dfs(v);
	}
}
int qry(int u,int v){
	if(dep[v]>dep[u]) swap(u,v);
	for(int dt=dep[u]-dep[v],j=LOGN;dt;j--) {
		if((1<<j)<=dt) dt-=(1<<j),u=fa[u][j];
	}
	if(u==v) return u;
	for(int j=LOGN;~j;j--) {
		if(fa[u][j]!=fa[v][j]) u=fa[u][j],v=fa[v][j];
	}
	return fa[u][0];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin>>n>>m>>S;
	for(int i=1;i<=n;i++) hd[i]=-1;
	for(int i=1;i<=n;i++) for(int j=0;j<=LOGN;j++) fa[i][j]=-1;
	for(int i=1,u,v;i<n;i++) {
		cin>>u>>v;
		if(u!=v) bld(u,v);
	}
	dfs(S);
	for(int i=1,u,v;i<=m;i++) {
		cin>>u>>v;
		cout<<qry(u,v)<<'\n';
	}
	return 0;
}
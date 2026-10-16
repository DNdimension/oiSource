#include <iostream>
#include <bitset>
using namespace std;
constexpr int N=3e5+2;
int n,m,T,tc,nc,gc,d[N],hd[N],nx[N<<1],to[N<<1];
bitset<N> vis;
bool f1,f2;
void build(int u,int v) {
	d[u]++,d[v]++;
	nx[++gc]=hd[u];
	hd[u]=gc, to[gc]=v;
	nx[++gc]=hd[v];
	hd[v]=gc, to[gc]=u;
}
void dfs(int u) {
	vis[u]=1;
	if(d[u]>1) nc++;
	if(!d[u]) f1=0;
	for(int v,j=hd[u];~j;j=nx[j]) {
		v=to[j];
		if(!vis[v]) dfs(v);
	}
}
int main() {
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) hd[i]=-1,vis[i]=d[i]=0;
		f2=tc=gc=0;
		f1=1;
		for(int i=1,u,v;i<=m;i++) {
			cin>>u>>v;
			build(u,v);
		}
		for(int i=1;i<=n;i++) {
			nc=0;
			if(!vis[i]) dfs(i),tc++;
			if(nc>1||tc>1) f2=1; 
		}
		if(!f1) cout<<"Brain Melt\n";
		else if(!f2) cout<<"2\n";
		else cout<<"Many\n";
	}
	return 0;
}
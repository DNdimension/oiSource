#include <iostream>
#include <queue>
using namespace std;
constexpr int N=2e5+2,M=1e6+2;
int T,n,m,gc,tc,d[3][N],a[N],hd[N],nx[M<<1],to[M<<1],wo[M<<1];
queue<int> Q;
void bld(int u,int v,int o) {
	nx[++gc]=hd[u];
	hd[u]=gc, to[gc]=v, wo[gc]=o;
	nx[++gc]=hd[v];
	hd[v]=gc, to[gc]=u, wo[gc]=o;
}
void topo() {
	tc=n;
	for(int u=1;u<=n;u++) if(!d[1][u]||!d[2][u]) Q.push(u);
	while(!Q.empty()) {
		int u=Q.front();
		Q.pop();
		if(!a[u]) {
			a[u]=(!d[2][u])?tc:-tc;
			tc--;
		}
		d[1][u]=d[2][u]=0;
		for(int v,o,j=hd[u];~j;j=nx[j]) {
			v=to[j],o=wo[j];
			if(!--d[wo[j]][v]) Q.push(v);
		}
	}
	if(!tc) {
		cout<<"YES\n";
		for(int u=1;u<=n;u++) cout<<a[u]<<" \n"[u==n];
	} else cout<<"NO\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int u=1;u<=n;u++) {
			a[u]=d[1][u]=d[2][u]=0;
			hd[u]=-1;
		}
		gc=0;
		for(int i=1,u,v,o;i<=m;i++) {
			cin>>o>>u>>v;
			d[o][u]++,d[o][v]++;
			bld(u,v,o);
		}
		topo();
	}
	return 0;
}
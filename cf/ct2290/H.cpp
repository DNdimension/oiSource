#include<iostream>
using namespace std;
constexpr int N=2e5+2;
int T,n,gc,mxc,sc[N],hd[N],nx[N<<1],to[N<<1];
void bld(int u,int v) {
	nx[++gc]=hd[u];
	hd[u]=gc,to[gc]=v;
	nx[++gc]=hd[v];
	hd[v]=gc,to[gc]=u;
}
void dfs(int u,int fa) {
	sc[u]++;
	for(int j=hd[u],v,mx=0;~j;j=nx[j]) {
		v=to[j];
		if(v==fa) continue;
		dfs(v,u);
		sc[u]+=sc[v];
		if(u!=1) {
			if(sc[v]>mx) {
				mxc=max(mxc,mx);
				mx=sc[v];
			}
			else mxc=max(mxc,sc[v]);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		mxc=0,gc=0;
		for(int i=1;i<=n;i++) {
			sc[i]=0;
			hd[i]=-1;
		}
		
		for(int i=1,u,v;i<n;i++) {
			cin>>u>>v;
			bld(u,v);
		}
		dfs(1,-1);
		for(int j=hd[1],v,mx1=0,mx2=0;~j;j=nx[j]) {
			v=to[j];
			if(sc[v]>=mx1) {
				mxc=max(mxc,mx2);
				mx2=mx1;
				mx1=sc[v];
			} else if(sc[v]>=mx2) {
				mxc=max(mxc,mx2);
				mx2=sc[v];
			} else mxc=max(mxc,sc[v]);
		}
		cout<<n-mxc<<'\n';
	}
	return 0;
}

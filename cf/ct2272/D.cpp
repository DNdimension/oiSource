#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int T,n,k,gc,tu,ti,d[N],nx[N<<1],hd[N],to[N<<1];
void bld(int u,int v) {
	d[u]++,d[v]++;
	nx[++gc]=hd[u];
	hd[u]=gc,to[gc]=v;
	nx[++gc]=hd[v];
	hd[v]=gc,to[gc]=u;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>k;
		tu=0;
		for(int i=1;i<=k;i++) {
			cin>>n;
			gc=0;
			for(int j=1;j<=n;j++) d[j]=0,hd[j]=-1;
			for(int j=1,u,v;j<n;j++) {
				cin>>u>>v;
				bld(u,v);
			}
			for(int u=1;u<=n&&!tu;u++) {
				if(d[u]!=1) continue;
				tu=to[hd[u]],ti=i;
			}
		}
		if(!tu) tu=ti=1;
		for(int i=1;i<=k;i++) if(i!=ti) 
			cout<<i<<" 1 "<<ti<<" "<<tu<<'\n';
	}
	return 0;
}
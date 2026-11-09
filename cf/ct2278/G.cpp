#include <iostream>
#include <queue>
using namespace std;
constexpr int N=2e5+2,MOD=998244353;
char ch;
int j,d,bi,T,n,gc,ans,hd[N],nx[N<<1],to[N<<1];
bool psd,raw[N],tar[N],f[2];
struct Node {int fa,u,dep,psd;} nd;
queue<Node> Q;
void bld(int u,int v) {
	nx[++gc]=hd[u];
	hd[u]=gc,to[gc]=v;
	nx[++gc]=hd[v];
	hd[v]=gc,to[gc]=u;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		ans=d=gc=0,f[1]=f[0]=bi=1;
		for(int i=1;i<=n;i++) hd[i]=-1;
		for(int i=1,u,v;i<n;i++) {
			cin>>u>>v;
			bld(u,v);
		}
		for(int i=1;i<=n;i++) {
			cin>>ch;
			raw[i]=ch-'0';
		}
		for(int i=1;i<=n;i++) {
			cin>>ch;
			tar[i]=ch-'0';
		}
		Q.push({-1,1,0,0});
		while(!Q.empty()) {
			nd=Q.front();
			Q.pop();
			if(nd.dep!=d) {
				if(!f[1]&&!f[0]) {
					ans=-1;
					break;
				} 
				ans=(ans+bi*f[1])%MOD;
				d++,bi=(bi<<1)%MOD;
				f[1]=f[0]=1;
			} 
			if(~nd.u) {
				psd=0;
				if(nd.psd&&raw[nd.u]) psd=1;
				raw[nd.u]^=nd.psd;
				if(raw[nd.u]^tar[nd.u]) {
					f[0]=0;
					if(raw[nd.u]) psd=1;
				} else f[1]=0;
				for(int j=hd[nd.u];;j=nx[j]) {
					if(~j) {
						if(to[j]!=nd.fa) Q.push({nd.u,to[j],nd.dep+1,psd});
						continue;
					}
					Q.push({0,-1,nd.dep+1,0});
					break;
				}
				
			}
//			cout<<nd.fa<<' '<<nd.u<<' '<<nd.dep<<' '<<f[1]<<' '<<f[0]<<'\n';
		}
		cout<<ans<<'\n';
		
		while(!Q.empty()) Q.pop();
	}
	return 0;
}
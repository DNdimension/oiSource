#include <iostream>
#include <bitset>
#include <algorithm>
#define LS o<<1
#define RS o<<1|1
using namespace std;
constexpr int N=2e5+2,INF=1e9;
struct SegTr {
	int nd[N<<2],lz[N<<2],sz;
	void ini(int n) {
		sz=n;
		for(int i=1;i<=(sz<<2);i++) lz[i]=nd[i]=0;
	}
	void psu(int o) {
		nd[o]=max(nd[LS],nd[RS]);
	}
	void psd(int o,int l,int r) {
		nd[LS]+=lz[o],nd[RS]+=lz[o];
		lz[LS]+=lz[o],lz[RS]+=lz[o];
		lz[o]=0;
	}
	bool bad(int o=1) {
		return (nd[o]>2);
	}
	void upd(int ul,int ur,int v) {
		if(ul<=ur) upd(1,1,sz,ul,ur,v);
//		cout<<ul<<' '<<ur<<' '<<v<<'\n';
	}
	void upd(int o,int l,int r,int ul,int ur,int v) {
		if(ul<=l&&r<=ur) {
			nd[o]+=v,lz[o]+=v;
//			cout<<l<<' '<<r<<' '<<nd[o]<<'\n';
			return;
		}
		psd(o,l,r);
		int mid=(l+r)>>1;
		if(ul<=mid) upd(LS,l,mid,ul,ur,v);
		if(mid+1<=ur) upd(RS,mid+1,r,ul,ur,v);
		psu(o);
	}
	int fnd(int o,int l,int r) {
//		cout<<l<<' '<<r<<' '<<nd[o]<<'\n';
		if(l==r) return l;
		psd(o,l,r);
		int mid=(l+r)>>1;
		if(bad(LS)) return fnd(LS,l,mid);
		return fnd(RS,mid+1,r);
	}
} tr;
int T,n,ans,p[N<<1],lst[N];
bitset<N> f;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		tr.ini(n);
		for(int i=1;i<=n;i++) {
			cin>>p[i];
			p[n+i]=p[i],f[i]=1,lst[p[i]]=0;
		}
		ans=lst[0]=lst[n+1]=0;
		for(int L,R,i=1;i<n*2;i++) {
			lst[p[i]]=i;
			L=max(1,i-n+1),R=min(n,i);
			tr.upd(L,R,1);
			tr.upd(L,lst[p[i]-1],-1);
			tr.upd(L,lst[p[i]+1],-1);
			for(int x;tr.bad();) {
				x=tr.fnd(1,1,n);
//				cout<<x<<'\n';
				tr.upd(x,x,-INF);
				f[x]=0;
			}
		}
//		for(int i=1;i<=n;i++) cout<<f[i]<<" \n"[i==n];
		for(int i=1;i<=n;i++) ans+=f[i];
		cout<<ans<<'\n';
	}
	return 0;
}
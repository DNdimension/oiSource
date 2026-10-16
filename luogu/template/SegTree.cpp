#include <iostream>
#define ll long long
#define LS o<<1
#define RS o<<1|1
using namespace std;
constexpr int N=1e5+2;
int T,n,q;
ll m;
struct SegTr {
	ll a[N<<2],ml[N<<2],ad[N<<2];
	int sz;
	void psd(int o,int l,int r) {
		int mid=(l+r)>>1;
		a[LS]=a[LS]*ml[o]%m,a[RS]=a[RS]*ml[o]%m;
		a[LS]=(a[LS]+ad[o]*(mid-l+1)%m)%m,a[RS]=(a[RS]+ad[o]*(r-mid)%m)%m;
		ml[LS]=ml[LS]*ml[o]%m,ml[RS]=ml[RS]*ml[o]%m;
		ad[RS]=(ad[RS]*ml[o]+ad[o])%m,ad[LS]=(ad[LS]*ml[o]+ad[o])%m;
		ad[o]=0,ml[o]=1;
	}
	void psu(int o) {
		a[o]=(a[LS]+a[RS])%m;
	}
	void ini(int n) {
		sz=n;
		for(int i=1;i<=(sz<<2);i++) ad[i]=a[i]=0,ml[i]=1;
	}
	void upd(int o,int l,int r,int ul,int ur,ll v,int t) {
		if(ul<=l&&r<=ur) {
			if(t==2) a[o]=(a[o]+v*(r-l+1)%m)%m,ad[o]=(ad[o]%m+v)%m;
			else a[o]=a[o]*v%m,ml[o]=ml[o]*v%m,ad[o]=ad[o]*v%m;
			return;
		}
		psd(o,l,r);
		int mid=(l+r)>>1;
		if(mid>=ul) upd(LS,l,mid,ul,ur,v,t);
		if(mid+1<=ur) upd(RS,mid+1,r,ul,ur,v,t);
		psu(o);
	}
	ll qry(int o,int l,int r,int ul,int ur) {
		if(ul<=l&&r<=ur) return a[o];
		psd(o,l,r);
		int mid=(l+r)>>1;
		ll ret=0;
		if(mid>=ul) ret=qry(LS,l,mid,ul,ur);
		if(mid+1<=ur) ret=(ret+qry(RS,mid+1,r,ul,ur))%m;
		return ret; 
	}
} tr;
int main() {
	T=1;
	while(T--) {
		ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cin>>n>>q>>m;
		tr.ini(n);
		for(int i=1,v;i<=n;i++) {
			cin>>v;
			v%=m;
			tr.upd(1,1,n,i,i,v,2);
		}
		for(int i=1,op,x,y,k;i<=q;i++) {
			cin>>op>>x>>y;
			if(op==3) cout<<tr.qry(1,1,n,x,y)<<'\n';
			else {
				cin>>k;
				tr.upd(1,1,n,x,y,k,op);
			}
		}
	}
	return 0;
}
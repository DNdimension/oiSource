#include <iostream>
#define LS o<<1
#define RS o<<1|1
using namespace std;
constexpr int N=2e6+5,INF=1e9+5;
int n,q,p,t,a[N],mn[N<<2],mx[N<<2],k[N<<2];
void bld(int l,int r,int o) {
	if(l==r) mn[o]=mx[o]=a[l],k[o]=0;
	else {
		int mid=l+(r-l>>1);
		bld(l,mid,LS);
		bld(mid+1,r,RS);
		if(mx[LS]>mn[RS]) k[o]=r-mid;
		else k[o]=max(k[LS],k[RS]);
		mn[o]=min(mn[LS],mn[RS]);
		mx[o]=max(mx[LS],mx[RS]);
	}
}
void edt(int l,int r,int o) {
	if(l==r) mn[o]=mx[o]=a[l];
	else {
		int mid=l+(r-l>>1);
		if(p<=mid) edt(l,mid,LS);
		else edt(mid+1,r,RS);
		if(mx[LS]>mn[RS]) k[o]=r-mid;
		else k[o]=max(k[LS],k[RS]);
		mn[o]=min(mn[LS],mn[RS]);
		mx[o]=max(mx[LS],mx[RS]);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(;n&(n-1);n++) a[n+1]=INF;
		bld(1,n,1);
		cout<<k[1]<<'\n';
		for(int i=1;i<=q;i++) {
			cin>>p;
			cin>>a[++p];
			edt(1,n,1);
			cout<<k[1]<<'\n';
		}
	}
	return 0;
}
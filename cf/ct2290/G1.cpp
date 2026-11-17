#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr int N=1e6+4;
int n,T,l,r,mxp;
ll k0,h0[N],h[N];
bool ck(int dh) {
//	cout<<dh<<'\n';
	ll k=k0;
	bool f=0;
	for(int i=1;i<=n+1;i++) h[i]=h0[i];
	for(int i=1,x,y,ft=1;k>=0&&!f;i=i%n+1) {
		x=i,y=i%n+1;
		if(h[x]>h[y]) swap(x,y);
		if(h[y]-h[x]>dh) {
			k-=h[y]-h[x]-dh;
			h[x]=h[y]-dh;
			ft=0;
		}
		if(i==n) {
//			for(int j=1;j<=n;j++) cout<<h[j]<<" \n"[j==n];
			if(ft) f=1;
			else ft=1;
		}
	}
	if(k>=0) return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k0;
		for(int i=1;i<=n;i++) cin>>h0[i];
		h0[n+1]=h0[1];
		l=0,r=h0[1],mxp=1;
		for(int i=1;i<=n;i++) r=max(r,(int)h0[i]);
//		cerr<<l<<' '<<r<<'\n';
		for(int mid=(l+r)>>1;l+1<r;mid=(l+r)>>1) {
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		if(l+1==r) {
			if(ck(l)) cout<<l;
			else cout<<r;
		} else cout<<l;
		cout<<'\n';
	}
	return 0;
}

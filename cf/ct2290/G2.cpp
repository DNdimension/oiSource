#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr int N=1e6+4;
int n,T,l,r,mxp,h0[N],h[N];
ll k0;
bool ck(int dh) {
	ll k=k0;
	for(int i=1;i<=n+1;i++) h[i]=h0[(mxp+i-2)%n+1];
	
	for(int i=1;i<=n;i++) {
		if(h[i]-h[i+1]>dh) {
			k-=h[i]-h[i+1]-dh;
			h[i+1]=h[i]-dh;
		}
	}
	for(int i=n;i;i--) {
		if(h[i+1]-h[i]>dh) {
			k-=h[i+1]-h[i]-dh;
			h[i]=h[i+1]-dh;
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
		l=0,r=1e9,mxp=0;
		for(int i=1;i<=n;i++) {
			if(h0[i]>h0[mxp]) mxp=i;
		}
		for(int mid=(l+r)>>1;l<r;mid=(l+r)>>1) {
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}

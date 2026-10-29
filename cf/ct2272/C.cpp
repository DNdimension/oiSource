#include <iostream>
#define ll signed long long 
using namespace std;
constexpr int N=2e5+2;
int T,k,n,x,l,r;
ll a[N];
bool f[N];
bool ck(ll k) {
	for(int i=1;i<=n+1;i++) f[i]=0;
	int c=x;
	for(ll i=1;i<=n&&c>=0;i++) {
		if(f[i]) continue;
		if(a[i+1]-a[i]<=k||a[i]-a[i-1]<=k) continue;
		if(a[i+1]-a[i]<=k*2) f[i+1]=1,c--;
		else if(a[i]-a[i-1]<=k*2) c--;
		else c--;
	}
//	cout<<k<<' '<<c<<'\n';
	return (c>=0);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>x;
		for(int i=1;i<=n;i++) cin>>a[i];
		l=1,r=0;
		for(int i=2;i<=n;i++) r=max(1LL*r,a[i]-a[i-1]);
		a[0]=-2e9,a[n+1]=2e9;
		for(int mid=(l+r)>>1;r>l+1;mid=(l+r)>>1) {
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		if(l==r) cout<<l<<'\n';
		else {
			if(ck(l)) cout<<l<<'\n';
			else cout<<r<<'\n';
		}
	}
	return 0;
}
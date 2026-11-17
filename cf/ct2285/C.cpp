#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr ll N=2e5+3,MOD=1e9+7;
int T,n;
ll ans,a[N],lw;
ll qpow(ll a,int n) {
	ll t=1;
	for(;n;) {
		if(n&1) t=t*a%MOD,n-=1;
		else a=a*a%MOD,n>>=1;
	}
	return t;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		ans=lw=1;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++) 
			if(a[i]==a[i-1]) lw=a[i];
		
		for(int i=n;a[i]>lw;i--) 
			ans=(ans+qpow(a[i]-1,n-i+1))%MOD;
		cout<<ans<<'\n';
	}
//	cout<<qpow(3,5);
	return 0;
}

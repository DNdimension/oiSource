#include <iostream>
#define ll long long 
using namespace std;
constexpr ll N=2e5+2,MOD=998244353;
int T;
ll l,r,ans,b[]={0,1,3,2,6,5};
ll f(ll n,ll k) {
//	cout<<n<<' '<<k<<'\n';
	if(n<6) return b[n];
	if(!k) return MOD;
	else {
		if(n>=(1LL<<k)) {
			ll ret;
			ret=min(k+1+(1LL<<k+1)-1-n,k+1+f(n-((1LL<<k)-2),k-1));
			return ret;
		}
		else return f(n,k-1);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>l>>r;
		ans=0;
		for(ll i=l;i<=r;i++) ans=(ans+f(i,60))%MOD;
		cout<<ans<<'\n';
	}
	
	return 0;
}
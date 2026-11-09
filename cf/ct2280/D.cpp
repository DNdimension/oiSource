#include <iostream>
#define QM(v) ((v)>=MOD?(v)-MOD:(v))
using namespace std;
constexpr int N=2e5+2,MOD=998244353;
int T,n,ans,mx,dp[N*3][3];
bool f[N*3];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		mx=0;
		cin>>n;
		for(int i=1;i<=n*3;i++) f[i]=0;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			f[x]=1,mx=max(mx,x);
		} 
		ans=(1LL*n*(n-1)/2)%(1LL*MOD);
		ans=QM(ans+n);
		for(int i=3;i<=mx;i++) {
			dp[i][0]=dp[i][1]=dp[i][2]=0;
			if(!f[i]) continue;
			dp[i][0]=QM((f[i-2]&f[i-3])+dp[i-2][2]+dp[i-2][1]);
			dp[i][1]=QM((f[i-1]&f[i-3])+dp[i-1][0]);
			dp[i][2]=QM((f[i-1]&f[i-2])+dp[i-1][1]);
			ans=QM(ans+dp[i][0]),ans=QM(ans+dp[i][1]),ans=QM(ans+dp[i][2]);
		}
		cout<<ans<<'\n';
	}
}


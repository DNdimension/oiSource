#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr int N=2e5+2;
int T,n,p[N];
ll dp[N<<1];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) p[i]=0;
		for(int i=1,t;i<=n*2;i++) {
			cin>>t;
			dp[i]=dp[i-1]+1;
			if(p[t]) dp[i]=max(dp[i],dp[p[t]-1]+1LL*(i-p[t]+1)*(i-p[t]+1));
			else p[t]=i;
		}
		cout<<dp[n*2]<<'\n';
	}
	return 0;
}


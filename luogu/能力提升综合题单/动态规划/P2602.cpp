#define ll long long 
#include <iostream>
using namespace std;
const int D=15;
ll l,r,dp[D],fl[10],fr[10];
void solve(ll k,ll *f) {
	int d=0;
	for(ll T=1;k>=T;T*=10LL,d++) {
		ll n=k/T%10LL;
		for(int i=0;i<n;i++) f[i]+=T;
		f[n]+=k%T+1LL;
		for(int i=0;i<=9;i++) f[i]+=n*dp[d];
		f[0]-=T;
	}
	return;
}
int main() {
	for(ll i=1,k=1;i<D;i++,k*=10LL) dp[i]=10LL*dp[i-1]+k;
	cin>>l>>r;
	solve(l-1,fl), solve(r,fr);
	for(int i=0;i<=9;i++) cout<<fr[i]-fl[i]<<' ';
	return 0;
}
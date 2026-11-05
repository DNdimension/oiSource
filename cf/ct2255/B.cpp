#include <iostream>
#define ll long long 
using namespace std;
constexpr ll N=1e6+2,MOD=998244353;
int T,n;
ll ans[2],pc[2],nc[2],jc[N];
string s;
char lst;
ll mi(ll a) {
	ll ret=1,tmp=a,n=MOD-2;
	while(n) {
		if(n&1LL) ret=ret*tmp%MOD,n--;
		else tmp=tmp*tmp%MOD,n>>=1LL;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	jc[0]=1;
	for(int i=1;i<N;i++) jc[i]=(jc[i-1]*i)%MOD;
	cin>>T;
	while(T--) {
		cin>>n>>s;
		pc[0]=pc[1]=nc[0]=nc[1]=0;
		lst='2';
		for(int i=0;i<n;i++) {
			if(s[i]==lst) nc[s[i]-'0']++;
			else lst=s[i],pc[s[i]-'0']++;
		}
		for(int i=0;i<2;i++) {
			if(!pc[i]) ans[i]=1;
			else ans[i]=jc[nc[i]+pc[i]-1]*mi(jc[nc[i]])%MOD*mi(jc[pc[i]-1])%MOD;
		}
			
		cout<<ans[1]*ans[0]%MOD<<'\n';
	}
	return 0;
}
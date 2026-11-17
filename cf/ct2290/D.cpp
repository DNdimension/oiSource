#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int n,T,ans,f[N];
char s[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>s[i];
		for(int i='a';i<='z';i++) f[i]=0;
		for(int i=1;2*i<=n;i++) {
			if(s[i]==s[n-i+1]) continue;
			if(s[i]>s[n-i+1]) swap(s[i],s[n-i+1]);
			f[s[i]]++,f[s[n-i+1]]--;
		}
		for(int i='a';i<='z';i++) {
			f[i]+=f[i-1];
			ans+=(f[i]>0);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

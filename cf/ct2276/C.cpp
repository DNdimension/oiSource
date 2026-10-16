#include <iostream>
#define ll long long 
using namespace std;
const int N=2e5+2;
int n,k,T;
ll s[N],c[N],ans;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		ans=0;
		cin>>n>>k;
		for(int i=0;i<k;i++) c[i]=0;
		for(int i=1;i<=n;i++) {
			cin>>s[i];
			s[i]=(s[i]+s[i-1])%k;			
		}
		for(int i=0,j=k+1;j<=n;i++,j++) {
			c[s[i]]++;
			ans+=c[s[j]];
//			cout<<i<<' '<<j<<' '<<ans<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
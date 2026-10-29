#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int T,ans,n,m,l[N],s[N];
int main() {
	cin>>T;
	while(T--) {
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++) l[i]=0;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			l[x]++;
		}
		s[m]=l[m];
		for(int i=m;i;i--) {
			s[i-1]=s[i]+l[i-1];
		}
		for(int i=m,t;i;i--) {
			t=s[i];
			if(2*i<=m) t+=l[2*i];
			ans=(ans>t?ans:t);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
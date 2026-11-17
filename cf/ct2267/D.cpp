#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+3;
int T,n,k,l;
bool f,p[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		f=1;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			p[x]=i&1;
		}
		l=1+n&1;
		for(int i=l;i<n&&f;i+=2) {
			if(p[i]^p[i+1]) continue;
			f=0;
		}
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

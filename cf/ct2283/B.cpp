#include <iostream>
using namespace std;
constexpr int N=5e3+2;
int T,n,a[N],c;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		c=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,t;i<=n;i++) {
			t=0;
			for(int j=1;j<=n;j++) t+=!(a[j]%a[i]);
			c=max(c,t);
		}
		cout<<n-c<<'\n';
	}
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,n,mn,mx;
int a[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
	mx=0,mn=1e9+1;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			mn=min(mn,a[i]),mx=max(mx,a[i]);
		}
		for(int l=1;mn<mx;l<<=1) {
			mn|=l;
			if(mn<mx) mx|=l;
//			cout<<l<<' '<<mx<<'\n';
		}
		cout<<mx<<'\n';
	}
	return 0;
}
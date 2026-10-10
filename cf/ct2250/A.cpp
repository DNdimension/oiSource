#include <iostream>
using namespace std;
int T,n,a[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n&1) {
			cout<<"NO\n";
			continue;
		}
		for(int i=3,x,y;i<=n;i+=2) {
			if(a[1]>a[i]) a[1]=a[i];
			if(a[i+1]>a[2]) a[2]=a[i+1];
		}
		if(a[1]-1>a[2]) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
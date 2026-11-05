#include <iostream>
using namespace std;
int T,l,r;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>l>>r;
		if(l*r<=0) cout<<max(0,abs(r+l)-1)<<'\n';
		else cout<<r-l<<'\n';
	}
	return 0;
}
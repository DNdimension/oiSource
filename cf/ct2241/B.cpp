#include <iostream>
using namespace std;
int T,n,k;
string ans;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		ans="1";
		for(n/=10;n;n/=10) ans+="0";
		ans+="1";
		cout<<ans<<'\n';
	}
	return 0;
}

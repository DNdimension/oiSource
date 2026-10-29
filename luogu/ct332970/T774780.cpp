#include <iostream>
using namespace std;
int t;
long long n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n&1LL) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
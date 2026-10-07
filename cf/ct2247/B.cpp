#include <iostream>
using namespace std;
int t,n,k,m;
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>k>>m;
		if(k>m) cout<<"NO\n";
		else {
			cout<<"YES\n";
			cout<<2*m-k+1;
			for(int i=2;i<=n;i++) cout<<" 1";
			cout<<'\n';
		}
	}
	return 0;
}
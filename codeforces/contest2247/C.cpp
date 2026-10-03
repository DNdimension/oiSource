#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int t,n,s[2][2],a[N];
int main() {
	cin>>t;
	while(t--) {
		s[0][0]=s[0][1]=s[1][0]=s[1][1]=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,b;i<=n;i++) {
			cin>>b;
			s[a[i]][b]++;
		}
		if(!s[1][0]) {
			if(!s[0][1]) cout<<"0\n";
			else if(!s[1][1]) cout<<"-1\n";
			else if(!s[0][0]) cout<<"-1\n";
			else cout<<"2\n";
		} else {
			if(s[1][0]&1) cout<<"1\n";
			else cout<<"2\n";
		}
	}
	return 0;
}
#include <iostream>
using namespace std;
int t,n,k,ans;
char ch;
int main() {
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n>>k;
		if(k>=n/2+1) {
			cout<<"-1\n";
			while(n--) cin>>ch;
			continue;
		}
		for(int i=1;i<=n;i++) {
			cin>>ch;
			if(i<=k&&ch=='L') ans++;
			if(n-i+1<=k&&ch=='R') ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int T,n,cnt,mx,mn;
char ch;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		cnt=mx=0,mn=1e9;
		for(int i=1;i<=n;i++) {
			cin>>ch;
			if(ch-'0') mx=max(mx,i),mn=min(mn,i),cnt++;
		}
		if(cnt==2) cout<<"1\n";
		else cout<<mx-mn<<'\n';
	}
	return 0;
}
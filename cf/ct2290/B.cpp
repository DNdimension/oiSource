#include <iostream>
using namespace std;
int ans,n,T;
char ch,lst,s[3]="RB";
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		ans=0,lst='B';
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>ch;
			if(ch==lst) ans++;
			lst=ch;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

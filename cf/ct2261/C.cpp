#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=1e6+2;
int T,n,c,s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		s=c=0;
		cin>>n;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			c+=x&1;
			s^=x&1;
		}
		if(n==1||!s||(n>=3&&c==1)||(c>=3&&c!=n)||c>=4) cout<<"Moggity\n";
		else cout<<"Larpity\n";
	}
	return 0;
}
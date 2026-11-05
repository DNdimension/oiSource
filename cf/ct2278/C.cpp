#include <iostream>
using namespace std;
bool f;
int T,n,s,a1,an;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		s=f=0;
		cin>>a1;
		for(int i=2,x;i<n;i++) {
			cin>>x;
			s+=x;
			if(x>1) f=1;
		}
		cin>>an;
		s+=a1+an;
		if(f) cout<<s-1<<'\n';
		else {
			if(a1>1||an>1) cout<<s-(n-1)<<'\n';
			else cout<<"-1\n";
		}
	}
	return 0;
}
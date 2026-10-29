#include <iostream>
using namespace std;
constexpr int N=1e2+2;
int T,n,c,k,t[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		c=0;
		for(int i=0;i<=n;i++) t[i]=0;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			t[x]++;
		}
		for(int i=0;i<=n;i++) {
			if(!t[i]||t[i]+c<k) {
				cout<<i<<'\n';
				break;
			}
			c+=t[i]-k;
		}
	}
	
	return 0;
}
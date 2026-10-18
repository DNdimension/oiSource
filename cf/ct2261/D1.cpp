#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,n,m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1,u,v;i<=m;i++) {
			cin>>u>>v;
		}
		n-=1;
		int l=(n+1)>>1;
		cout<<(n?n-l+1:0)<<'\n';
		for(int i=1;i+l-1<=n&&n;i++) cout<<i<<' '<<i+l-1<<'\n';
	}
	return 0;
}
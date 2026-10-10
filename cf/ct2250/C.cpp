#include <iostream>
using namespace std;
constexpr int N=5e3+2;
int T,n,k,l[N],r[N],u[N],v[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) 
			cin>>l[i]>>r[i]>>u[i]>>v[i];
		int m=n;
		for(;~m;m--) {
			int c=1;
			for(int i=1;i<=n&&c-1<m;i++) {
				if(l[i]<=c&&c<=r[i]) continue;
				if(m-v[i]+1<=c&&c<=m-u[i]+1) continue;
				++c;
			}
			if(c-1==m) {
				cout<<m<<'\n';
				break;
			} 
		}
	}
	return 0;
}
#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int T,n,c,p[N],r[N];
bool f;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		c=f=0;
		for(int i=1;i<=n;i++) cin>>p[i];
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			if(x!=r[c]) {
				r[++c]=x;
			}
		}
		for(int i=1,j=1;i<=n&&j<=c;) {
			while(r[j]!=p[i]&&i<=n) i++;
			if(r[j]==p[i]&&j==c) f=1;
			j++;
		}
		cout<<(f?"YES":"NO")<<'\n';
	}
	return 0;
}
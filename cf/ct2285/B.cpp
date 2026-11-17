#include <iostream>
#define ll long long 
using namespace std;
constexpr int N=3e5+3;
int T,n,k,c;
ll f[N];
char ch;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	for(int i=1;i<N-1;i++) f[i]=f[i-1]+i;
	while(T--) {
		cin>>n>>k;
		c=0;
		for(int i=1;i<=n;i++) {
			cin>>ch;
			c+=ch-'0';
		}
		c=max(c,n-c);
		c=min(c+k,n);
		cout<<f[c]+f[n-c]+1<<'\n';
	}
	return 0;
}

#include <iostream>
#include <bitset>
using namespace std;
const int N=1e5+2;
int n,m,i;
bitset<N> f;
string c[N];
int main() {
	cin>>n>>m;
	for(int ff;i<=n-1;i++) {
		cin>>ff>>c[i];
		if(ff) f[i]=1;
	}
	i=0;
	for(int j,k;m;m--) {
		cin>>j>>k;
		if(f[i]^j) i=(i+k)%n;
		else i=(i+n-k)%n;
	}
	cout<<c[i];
	return 0;
}
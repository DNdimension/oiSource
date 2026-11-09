#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,n,k,c,a[N],b[N];
long long s;
bool f;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		f=1;
		c=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=n-k+1;i<=n;i++) b[++c]=a[i];
		for(int i=n-k;i;i--) b[++c]=a[i];
		c=1,s=b[1];
		for(int i=2;i<=n&&f;i++) {
			if(s-1LL*(i-1)*b[i]<=0) ++c;
			s+=b[i];
			if(c>k) f=0;
		}
//		cout<<c<<'\n';
		if(f) {
			cout<<"YES\n";
			for(int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
		} else cout<<"NO\n";
	}
	return 0;
}
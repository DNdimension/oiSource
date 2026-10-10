#include <iostream>
#define ll long long 
using namespace std;
constexpr int N=2e5+2;
int c,T,a[N],f[N];
ll n,k;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		if(k<((n-1)<<1)||k>((n*n-(n&1LL))>>1)||k&1LL) {
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<=n;i++) f[i]=0;
		c=0;
		k-=((n-1)<<1);
		for(int i=n-1;k&&i>=3;i--) {
			if(k>=((i-2)<<1)) k-=((i-2)<<1),a[++c]=i,f[i]=1;
			if(f[i]) i--;
		}
		for(int i=1;i<=n;i++) if(!f[i]) a[++c]=i;
		for(int i=1;i<c;i++) cout<<a[i]<<' '<<a[i+1]<<'\n';
	}
	return 0;
}
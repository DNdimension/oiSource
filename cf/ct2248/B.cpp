#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,n,m,a[N],b[N];
bool f[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		f[0]=1;
		for(int i=1;i<=n;i++) cin>>a[i],f[i]=0;
		for(int i=1;i<=m;i++) cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		for(int i=1,j=1;f[0]&&j<=m;i++,j++) {
			if(i>n||a[i]>b[j]) f[0]=0;
			else f[i]=1;
		}
//		cout<<f[1]<<'\n';
		for(int j=m,i=n;f[0]&&j;j--,i--) {
			while(i>0&&f[i]) i--;
			if(i<1||a[i]<b[j]) f[0]=0;
			else f[i]=1;
		}
		if(f[0]) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}


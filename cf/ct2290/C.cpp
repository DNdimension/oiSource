#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int a[N],b[N],n,T,ans;
bool f[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) f[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		b[n+1]=ans=0;
		sort(a+1,a+n+1);
		for(int i=1,l=1,r=n;i<=n;i++) {
			if(a[i]>b[l-1]) b[l++]=a[i];
			else b[r--]=a[i];
		}
		for(int i=1;i<=n;i++) if(b[i]>b[i-1]) f[i]=1;
		for(int i=n;i;i--) if(b[i]>b[i+1]) f[i]=1;
		for(int i=1;i<=n;i++) ans+=f[i];
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
	}
	return 0;
}

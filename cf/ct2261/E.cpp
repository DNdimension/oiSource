#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=4e5+2;
int T,n,k,ad,ans,a[N];
char ch;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		ad=ans=0;
		for(int i=1;i<=n;i++) {
			cin>>ch;
			if(ch=='(') a[i]=1;
			else a[i]=-1;
		}
		for(int i=1;i<n&&k;i++) {
			if(a[i]+a[i+1]) continue;
			a[i]=a[i+1]=0;
			cout<<i<<' '<<ad<<'\n';
			i++,ad++,k--;
		}
		for(int i=1;i<n;i++) {
			a[i]=a[i-1]+a[i];
			if(a[i+1]==-1) ans=max(ans,a[i]);
		}
		cout<<ans+ad<<'\n';
	}
	return 0;
}
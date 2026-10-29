#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int t,ans,f,n,a[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[n+1]=f=0,ans=n;
		for(int i=1;i<n;) {
			if(a[i+1]==a[i]) {
				i+=2,ans--;
				while(a[i]==a[i-1]&&i<=n) {
					a[i-1]=0;
					i++,ans--;
				}
			} else i++;
		}
		for(int i=1,j=1,p,q;i<n&&j<=n&&!f;i=j+(a[i]==a[j])) {
			j=i+1;
			while(j<n&&!a[j]) j++;
			p=j+1;
			q=p+1;
			while(q<=n&&!a[q]) q++;
			if(a[i]==a[j]&&j-i+1>1&&q<=n&&a[p]==a[q]&&q-p+1>1) f=2;
		}
		for(int i=1,j;i<n&&!f;i=j+(a[i]==a[j])) {
			j=i+1;
			while(j<n&&!a[j]) j++;
			if(i-2>=0&&a[j]==a[i]&&a[i-2]!=a[i]) f=1;
			else if(j+2<=n+1&&a[j]==a[i]&&a[j+2]!=a[j]) f=1;
		}
		cout<<ans+f<<'\n';
	}
	return 0;
}
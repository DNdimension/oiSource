#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=5e3+5;
int T,n,ans,k,p,m,sum,a[N],b[N];
bool f;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k>>p>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		f=sum=ans=0;
		for(int i=1;i<=n;i++) b[i]=a[i];
		sort(b+1,b+n+1);
		for(int i=1,c=1;c<=n-k;i++) {
			if(!f&&b[i]==a[p]) f=1;
			else sum+=b[i],++c;
		}
		
		if(p>k) {
			for(int i=1;i<=n;i++) b[i]=a[i];
			sort(b+1,b+1+p-1);
			for(int i=1;i<=p-k;i++) m-=b[i];
			if(m<a[p]) {
				cout<<0<<"\n";
				continue;
			} 
		}
		
		ans=m/(sum+a[p]);
		if(m%(sum+a[p])>=a[p]) ans++;
		cout<<ans<<'\n';
		
	}
	return 0;
}

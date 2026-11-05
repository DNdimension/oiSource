#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,k,n,a[N],t[N],b[N],x,c;
bool f;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		c=0,f=1;
		cin>>n>>k;
		for(int i=1;i<=n;i++) t[i]=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			t[a[i]]++;
		}
		for(int i=1,k2=k;i<=n&&k2>0;i++) {
			k2-=t[i];
			if(k2<=0) x=i;
		}
		for(int i=1;i<=n;i++) 
			if(a[i]<=x) b[++c]=a[i];
		for(int i=1,j=c;i<j&&f;) {
			if(b[i]==b[j]) i++,j--;
			else if(b[i]==x) i++,t[x]--;
			else if(b[j]==x) j--,t[x]--;
			else f=0;
		}
		for(int i=1;i<=x;i++) k-=t[i];
		if(k>1) f=0;
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
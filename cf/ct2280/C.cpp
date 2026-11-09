#include <iostream>
using namespace std;
constexpr int N=3e5+2;
int T,n,a[N],l,r,mx,mn;
bool ck(int v) {
	bool ret=0;
	int i,j,c=0;
	for(i=2;i<=n;i++) c+=(abs(a[i]-a[i-1])>v);
	if(c>2) return 0;
	if(c==2) {
		for(i=2;i<=n;i++) {
			if(abs(a[i]-a[i-1])>v) break;
		}
		for(j=n-1;j;j--) {
			if(abs(a[j]-a[j+1])>v) break;
		} 
		for(int k=i;k<j;k++) if(2*abs(a[k]-a[k+1])>v) return 0;
		if(abs(2*a[i]-a[j+1])>v) return 0;
		if(abs(2*a[j]-a[i-1])>v) return 0;
		return 1;
	}
	
	
	for(i=2;i<=n;i++) {
		if(abs(a[i]-a[i-1])>v) break;
	}
	if(i>n) return 1;
	for(j=i;j<=n&&!ret;) {
		if(abs(2*a[j]-a[i-1])<=v) {
			if(j==n||abs(2*a[i]-a[j+1])<=v) ret=1; 
		}
		if(!ret) {
			if(j<n&&2*abs(a[j]-a[j+1])<=v) j++;
			else break;
		}
	}
//	if(v==5) cout<<i<<"===\n";
	i--;
	for(int j=i;j&&!ret;) {
		if(abs(2*a[j]-a[i+1])<=v) {
			if(j==1||abs(2*a[i]-a[j-1])<=v) ret=1;
		} 
//		if(v==5) cout<<j<<' '<<ret<<'\n';
		if(!ret) {
			if(j>1&&2*abs(a[j]-a[j-1])<=v) j--;
			else break;
		}
	}
	return ret;	
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		mn=1e9,mx=0;
		for(int i=1;i<=n;i++) 
			mn=min(mn,a[i]),mx=max(mx,a[i]);
		r=mx-mn,l=0;
		for(int mid=(l+r)/2;l+1<r;mid=(l+r)/2) {
//			cout<<l<<' '<<r<<'\n';
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
//			cout<<l<<' '<<r<<'\n';
		if(l==r) cout<<l<<'\n';
		else if(ck(l)) cout<<l<<'\n';
		else cout<<r<<'\n';
	}
}
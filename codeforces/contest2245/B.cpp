#include <iostream>
#define ll long long
using namespace std;
const int N=2e5+2;
int t,c,n,a[N],aa[N],p1,p2,p;
ll ans;
void bgs(int l,int r) {
	if(l==r) return;
	int mid=l+r>>1;
	bgs(l,mid);
	bgs(mid+1,r);
	p=p1=l,p2=mid+1;
	while(p1<=mid&&p2<=r) {
		if(a[p1]<a[p2]) aa[p++]=a[p1++];
		else aa[p++]=a[p2++];
	}
	while(p1<=mid) aa[p++]=a[p1++];
	while(p2<=r) aa[p++]=a[p2++];
	for(p=l;p<=r;p++) a[p]=aa[p];
}
int main() {
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n>>c;
		for(int i=1;i<=n;i++) cin>>a[i];
		bgs(1,n);
		if(a[1]>=c) p=0;
		else {
			for(p=1;a[p]<=c&&p<=n;) p++;
			p--; 
		}
		for(p1=1,p2=n;p1<p&&p2>p;p1++,p2--) ans+=1LL*(a[p2]-c);
		if(p1==p2) {
			ans+=1LL*(a[p1]-c);
		} else if(p1>=p) {
			for(;p2>p;p2--) ans+=1LL*(a[p2]-c);
		} else {
			for(;p1<p2;p1++,p2--) ans+=1LL*(a[p2]-c);
			if(p1==p2) ans+=1LL*(a[p2]-c);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
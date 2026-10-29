#include <iostream>
#define ll long long 
#define SI (1LL*a[i]+b[i]+c[i])
using namespace std;
constexpr int N=2e5+2;
int T,n,a[N],b[N],c[N];
ll k,l,r;
bool chk(ll v) {
	ll w=k;
	for(int i=1;i<=n&&w>=0;i++) {
		if(SI>=v) continue;
		if(a[i]==b[i]) {
			if(b[i]==c[i]) w=-1;
			else if(b[i]<c[i]) w-=v-(SI-1)+1;
			else w-=v-SI;
		} else if(a[i]<b[i]) {
			if(b[i]==c[i]) w-=v-(SI-1)+1;
			else if(b[i]<c[i]) {
				ll cost=min(1LL*b[i]-a[i],1LL*c[i]-b[i])+1;
				w-=v-(SI-cost)+cost;
			} else w-=v-SI;
			
		} else w-=v-SI;
	}
	return (w>=0);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		r=-1e15,l=1e15;
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>b[i]>>c[i];
			r=max(r,SI+k);
			l=min(l,SI-k);
		}
		for(ll mid=(l+r)/2LL;r>l+1;mid=(l+r)/2LL) {
			if(chk(mid)) l=mid;
			else r=mid-1;
		}
		if(l==r) cout<<l<<'\n';
		else {
			if(chk(r)) cout<<r<<'\n';
			else cout<<l<<'\n';;
		}
	} 
	return 0;
}
#include <iostream>
#define ll long long
using namespace std;
constexpr int N=5e5+1;
int n,m;
struct BIT {
	ll a[N];
	int sz;
	int lb(int x) {return x&(-x);}
	void upd(int x,int k) {
		for(;x<=sz;x+=lb(x)) a[x]+=k;
	}
	ll qry(int x) {
		ll r=0;
		for(;x;x-=lb(x)) r+=a[x];
		return r; 
	}
} tr;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	tr.sz=n;
	for(int i=1,x;i<=n;i++) {
		cin>>x;
		tr.upd(i,x);
	}
	for(int i=1,o,x,y;i<=m;i++) {
		cin>>o>>x>>y;
		if(o==1) tr.upd(x,y);
		else cout<<tr.qry(y)-tr.qry(x-1)<<'\n';
	}
	return 0;
}
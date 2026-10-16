#include <iostream>
#define ll long long 
using namespace std;
constexpr int N=5e5+2;
int n,m,r[N];
struct BIT {
	ll d[N],d1[N];
	int sz;
	int lb(int x) {return x&(-x);}
	void upd(int x,int k) {
		for(int y=x;y&&y<=sz;y+=lb(y)) d[y]+=k,d1[y]+=x*k;
	}
	ll qry(int x) {
		ll ans=0;
		for(int y=x;y;y-=lb(y)) ans+=(x+1)*d[y]-d1[y];
		return ans;
	}
} tr;
int main() {
	cin>>n>>m;
	tr.sz=n;
	for(int i=1;i<=n;i++) cin>>r[i];
	for(int i=1;i<=n;i++) tr.upd(i,r[i]-r[i-1]);
	for(int i=1,o,x,y,k;i<=m;i++){
		cin>>o>>x;
		if(o==1) {
			cin>>y>>k;
			tr.upd(x,k);
			tr.upd(y+1,-k);
		} else {
			cout<<tr.qry(x)-tr.qry(x-1)<<'\n';
		}
	}
	return 0;
}
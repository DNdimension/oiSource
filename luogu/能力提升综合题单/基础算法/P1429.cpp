#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define dis0(m,n) pw2((m).x-(n).x)+pw2((m).y-(n).y)
#define pw2(m) (m)*(m)
using namespace std;
constexpr int N=4e5+2;
struct P{
	long long x,y;
} p[N],pp[N];
int n,p1;
long long ans0;
void solve(int l,int r) {
	if(l==r) return;
	if(l+1==r) {
		ans0=min(ans0,dis0(p[l],p[r]));
		return;
	}
	int mid=l+r>>1;
	solve(l,mid-1);
	solve(mid+1,r);
	
	p1=0;
	for(int i=l;i<=r;i++) if(ans0>pw2(p[i].x-p[mid].x)) pp[++p1]=p[i];
	sort(pp+1,pp+p1+1,[](const P& a,const P& b){
		if(a.y!=b.y) return a.y<b.y;
		return a.x<b.x;
	});
	for(int i=1;i<=p1;i++) {
		for(int j=i+1;j<=p1&&ans0>pw2(pp[i].y-pp[j].y);j++) {
			ans0=min(ans0,dis0(pp[i],pp[j]));
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	sort(p+1,p+n+1,[](const P& a,const P& b){
		if(a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	});
//	for(int i=1;i<=n;i++) cout<<p[i].x<<' '<<p[i].y<<'\n';
	ans0=dis0(p[1],p[2]);
	solve(1,n);
	cout<<ans0;
	return 0;
}
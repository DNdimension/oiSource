#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr int N=2e5+2;
struct Num {
	ll v,p;
} b[N];
bool CMP(Num n1,Num n2) {
	if(n1.v==n2.v) return n1.p>n2.p;
	return n1.v>n2.v;
}
int T,n,a[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) b[i].p=i,b[i].v=b[i-1].v+a[i-1];
		sort(b+1,b+n+1,CMP);
		for(int i=1;i<=n;i++) a[b[i].p]=i;
		for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	}
	return 0;
}
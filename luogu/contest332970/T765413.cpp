#include <iostream>
#define MR 998244353ll
using namespace std;
const int N=5e5+2,M=32;
long long ans;
int n,t,l1[M],l2[M],a[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	t=-1;
	for(int i=1,j=0,k;i<=n;i++,j=0) {
		cin>>a[i];
		if(!a[i]) continue;
		for(k=a[i];k;j++) if(k&(1<<j)) k-=(1<<j);
		t=max(t,--j);
	}
	for(int i=0;i<=t;i++) l1[i]=l2[i]=n+1;
	for(int i=n,lst=n+1;i;i--,lst=n+1) {
		for(int j=t;~j;j--) {
			if((1<<j)&a[i]) {
				l2[j]=l1[j];
				l1[j]=i;
			}
			ans=(ans+(1<<j)%MR*(n+1-min(l1[j],lst))%MR)%MR;
			lst=min(lst,l2[j]);
		}
	}
	cout<<ans;
	return 0;
}
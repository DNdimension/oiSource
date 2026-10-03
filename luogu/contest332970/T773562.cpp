#include <bits/stdc++.h>
using namespace std;
const int N=7e5+2;
int t,n,q,b[N];
long long a[N];
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int op,l,r,i=1;i<=q;i++) {
			cin>>op>>l>>r;
			if(op&1) {
				for(int j=l;j<=r;j++) a[j]+=1LL*b[j];
			} else {
				int k=a[l];
				for(int j=l+1;j<=r;j++) k=gcd(k,a[j]);
				cout<<k<<'\n';
			}
		}
	}
	return 0;
}
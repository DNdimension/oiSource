#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int n,k,T,s,f[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		s=0;
		for(int i=1;i<=n;i++) f[i]=0;
		f[1]=1;
		for(int i=2,l=0,r=0,sf=0;i<=n;) {
			if(r<=i-1) sf=(sf+f[r++]);
			else if(l<max(1,i-k)) sf=(sf-f[l++]);
			else f[i++]=(1+sf);
		}
//		for(int i=1;i<=n;i++) cout<<f[i]<<" \n"[i==n];
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			x&=1;
			s=(f[i]*x+s)&1;
		}
		if(s) cout<<"Alice\n";
		else cout<<"Bob\n";
		
	}
	return 0;
}

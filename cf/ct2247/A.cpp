#include <iostream>
using namespace std;
const int N=102;
int t,n,c,s,a[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		c=s=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			s+=a[i];
		}
		s=(s>0)?s:-s;
		for(int i=1;i<n;i+=2) {
			if(a[i]*a[i+1]>0) c+=1;
		}
		
		if(s%4==0&&abs(s/4)<=c) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
#include <iostream>
using namespace std;
int t,n,k,p;
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>k;
		if(k==n) {
			cout<<"YES\n";
			for(int i=1;i<=n-1;i++) cout<<i<<' ';
			cout<<0<<'\n';
		} else {
			p=-1;
			for(int i=n;i;i>>=1) p++;
			if(k>=1<<(p+1)) cout<<"NO\n";
			else if(k>=1<<p) {
				cout<<"YES\n";
				k^=n;
				for(int i=1;i<=k-1;i++) cout<<i<<' ';
				for(int i=k+1;i<=n-1;i++) cout<<i<<' ';
				cout<<"0 ";
				cout<<k<<'\n';
			} else {
				k^=n;
				if(n==(1<<p)) cout<<"NO\n";
				else {
					cout<<"YES\n";
					k^=(n-1);
					for(int i=1;i<=k-1;i++) cout<<i<<' ';
					for(int i=k+1;i<=n-2;i++) cout<<i<<' ';
					cout<<"0 ";
					if(k) cout<<k<<' ';
					cout<<n-1<<'\n';
				}
			}
		}
	}
	return 0;
}
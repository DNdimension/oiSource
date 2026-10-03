#include <iostream>
#define lli long long int 
using namespace std;
const int N=2e3+2;
int T,f;
lli k,n,a[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		f=0;
		cin>>n>>k>>a[1];
		for(int i=2;i<=n;i++) {
			cin>>a[i];
			if(a[i]!=a[i-1]) f=1;
		}
		if(f) {
			cout<<"No\n";
			continue;
		}
		if(!k&&!a[1]) cout<<"No\n";
		else if(!k||!a[1]) cout<<"Yes 1 1\n";
		else if(abs(a[1]*n)>=abs(k)&&k/a[1]>0&&!(k%a[1])) cout<<"No\n";
		else cout<<"Yes 1 1\n";
	}
}
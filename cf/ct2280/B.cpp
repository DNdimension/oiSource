#include <iostream>
using namespace std;
constexpr int N=1e2+2;
int T,n,k,k2;
int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		cout<<"? 1 "<<n<<endl;
		cin>>k;
		if(!k||k==n) cout<<"! NO"<<endl;
		else {
			cout<<"? 1 "<<k<<endl;
			cin>>k2;
			if(k==k2) cout<<"! NO"<<endl;
			else cout<<"! YES"<<endl;
		}
	}
	return 0;
}
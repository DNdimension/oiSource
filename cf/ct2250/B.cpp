#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int T,n,k,a[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		if(n-1==k) {
			cout<<"-1\n";
			continue;
		}
		n-=k+2;
		for(int q=k/2;~q;q--) cout<<'0';
		for(int p=(k+1)/2;~p;p--) cout<<'1';
		for(;n>1;n-=2) cout<<"01";
		if(n) cout<<"0";
		cout<<'\n';
	}
	return 0;
}
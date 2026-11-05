#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int T,n,t,p,m,ck;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		ck=t=m=0;
		for(int i=0;(1<<i)<=n;i++) p=i;
//		cout<<p<<'\n';
		for(int i=1;i<n;i++) m^=i;
		m^=(n<<1);
		for(int i=p;i;i--) 
			if(!((1<<i)&m)) m^=1<<(i-1),t|=1<<(i-1);
//		cout<<t<<'\n';
		for(int i=1;i<=n;i++) cout<<(i==t||i==n)<<" \n"[i==n];
	}
	return 0;
}
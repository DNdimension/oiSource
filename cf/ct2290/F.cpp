#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int n,T,p[N];
bool f[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) f[i]=0;
		f[0]=1;
		for(int i=1,x,j;i<=n;i++){
			cin>>x;
			if(!f[0]) continue;
			j=x+n-i+1;
			if(j>n||j<1||f[j]) f[0]=0;
			else p[j]=i,f[j]=1;
//			cerr<<i<<' '<<j<<'\n';
		}
		
		if(f[0]) for(int i=1;i<=n;i++) cout<<p[i]<<" \n"[i==n];
		else cout<<"-1\n";
	}
	return 0;
}

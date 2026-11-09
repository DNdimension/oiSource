#include <iostream>
using namespace std;
constexpr int N=4e3+5,MOD=998244353;
int T,n,m,f[N],s[N];
int main() {
	cin>>T;
	while(T--) {
		cin>>n>>m;
		f[2]=1;
		for(int j=3;j<=m+2;j++) f[j]=0;
		
		for(int i=n-1;i;i--) {
			for(int j=2;j<=m+2;j++) 
				s[j]=(s[j-1]+f[j])%MOD;
			f[2]=(1+s[2])%MOD;
			for(int j=3;j<=m+2;j++) 
				f[j]=(s[j]+MOD-s[j/2])%MOD;
			
		}
		cout<<f[m+2]<<'\n';
		
	}
	return 0;
}
#include <iostream>
using namespace std;
constexpr int N=2e5+2;
bool f[N][2];
char ch,o;
int c[2],n,T;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		o=c[0]=c[1]=0;
		for(int j=0;j<=1;j++) for(int i=1;i<=n;i++) {
			cin>>ch;
			f[i][j]=(ch=='f');
			c[j]+=f[i][j];
		}
		if(c[1]>c[0]) o=1;
		for(int i=2;i<=n&&c[o]>c[o^1]+1;i++) {
			if(f[i][o]&&f[i-1][o]) f[i][o]=f[i-1][o]=0,c[o]-=2;
		}
		cout<<c[o]-c[o^1]<<'\n';
		
	}
	return 0;
}
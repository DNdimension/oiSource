#include <iostream>
#define ll long long 
using namespace std;
constexpr ll N=5e3+2,MOD=998244353;
int T,n;
ll ans1,ans2,tmp,c[2],f[N],g[N][N];
bool a[N];
char ch;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f[2]=f[3]=1;
	for(int i=4;i<N;i++) f[i]=(f[i-2]+f[i-3])%MOD;
	g[1][1]=1;
	for(int i=2;i<N;i++) for(int j=1;j<=i;j++) 
		g[i][j]=(g[i-1][j-1]+g[i-1][j]*j%MOD)%MOD;
	cin>>T;
	while(T--) {
		ans1=c[0]=c[1]=0;
		ans2=1;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>ch;
			a[i]=ch-'0';
		}
		for(int i=1,j;i<=n;) {
			if(i<n&&a[i]!=a[i+1]) {
				for(j=i;j<n&&a[j]!=a[j+1];j++);
				ans1+=2*(j-i+1);
				ans2=ans2*f[j-i+1]%MOD;
				i=j+1;
			} else {
				for(j=i;j<n&&a[j]==a[j+1];j++);
				if(j==n) j++;
				c[a[i]]+=j-1-i+1;
				ans1+=j-1-i+1;
				i=j;
			}
		}
		for(int i=0,j;i<=1;i++,ans2=ans2*max(tmp,1LL)%MOD) for(j=1,tmp=0;j<=c[i];j++) 
			tmp=(tmp+g[c[i]][j])%MOD;
		cout<<ans1<<' '<<ans2<<'\n';
	}
	return 0;
}
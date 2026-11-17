#include <iostream>
#define ll long long 
using namespace std;
constexpr int N=3e5+2,K=15;
int T,n,x,mx,arr[N],p[N],c[N],f[N][K];
ll s[N],ans;
bool np[N];
void ini() {
	for(int i=2;i<=N-2;i++) {
		if(np[i]) continue;
		f[i][++c[i]]=i;
		for(int j=2;1LL*j*i<=N-2;j++) {
			np[j*i]=1;
			f[i*j][++c[i*j]]=i;
		}
	}
}
int gcd(int a,int b) {
	if(b>a) swap(a,b);
	while(b) {
		a%=b;
		swap(a,b);
	}
	return a;
}
int main() {
	ini();
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		mx=0;
		cin>>n>>x;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			mx=max(mx,arr[i]);
		}
		for(int j=1;j<=c[x];j++) s[f[x][j]]=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=c[arr[i]];j++) s[f[arr[i]][j]]=0;
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=c[arr[i]];j++) s[f[arr[i]][j]]+=arr[i];
		}
		ans=0;
		for(int j=1;j<=c[x];j++) ans=max(ans,s[f[x][j]]);

		cout<<ans<<'\n';
	}
	return 0;
}

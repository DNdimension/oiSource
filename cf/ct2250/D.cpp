#include <iostream>
#include <bitset>
#define ll long long 
#define MOD 998244353
using namespace std;
constexpr int N=1e6+2;
int T,n,v[N];
bitset<N> vis,f,r;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<n;i++) cin>>v[i];
		v[n]=0;//ciao
		f[1]=r[n-1]=1;
		for(int i=2;i<n;i++) f[i]=f[i-1]&&(v[i]>=v[i-1]);
		for(int i=n-2;i;i--) r[i]=r[i+1]&&(v[i]>=v[i+1]);
		ll ans=0,fl=1;
		for(int i=1;i<n&&fl;i++) {
			if(v[i]==n) fl=0;
			if(!f[i]||!r[i]) continue;
			if(v[i]==v[i+1]) continue;
			for(int j=1;j<=n;j++) vis[j]=0;
			ll t=1,u=0,w;
			for(int j=1,k=n-1;j<=k;) {
				
				if(j==i) w=v[k--];
				else if(k==i) w=v[j++];
				else if(v[j]<v[k]) w=v[j++];
				else if(v[k]<v[j]) w=v[k--];
				else {
					fl=0;
					break;
				}
				if(vis[w]) {
					if(w>u) t=t*(w-u)%MOD;
					else fl=0;
				}
				else vis[w]=1;
				u++;

			}
			ans=(ans+t)%MOD*fl;
		}
		cout<<ans*2%MOD<<'\n';
	}	
	return 0;
}
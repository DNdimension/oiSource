#include <iostream>
using namespace std;
constexpr int N=200;
int T,n,k,a[N],mex[N],mt,mg,g,u,v;
bool f[N];
int gmex() {
	for(int i=0;i<=n;i++) f[i]=0;
	int c=0;
	for(int i=1,p=0;i<=n;i++) {
		f[a[i]]=1;
		while(f[p]) p++;
		mex[++c]=p;
	}
	return mex[c-k+1];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		mt=gmex();
		mg=-1;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				swap(a[i],a[j]);
				g=gmex();
				if(g>mg) u=i,v=j,mg=g;
				swap(a[i],a[j]);
			}
		}
		if(mt>=mg) cout<<"-1\n";
		else cout<<u<<' '<<v<<'\n';
	}
	return 0;
}
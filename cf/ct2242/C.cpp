#include <iostream>
using namespace std;
constexpr int N=3e5+2;
int n,k,T,cnt,ans,mxt,t[N];
bool f[N];
struct Block {
	int w,c;
} b[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		mxt=ans=0;
		b[1].c=cnt=1;
		cin>>n>>k;
		for(int i=1;i<=n;i++) f[i]=1,t[i]=0;
		cin>>b[1].w;
		for(int i=2,x;i<=n;i++) { 
			cin>>x;
			if(x==b[cnt].w) b[cnt].c++;
			else b[++cnt]={x,1};
		}
		for(int i=1;i<=cnt;i++) t[b[i].c]++,mxt=max(mxt,b[i].c);
		for(int i=mxt-1;i;i--) t[i]+=t[i+1];
		for(int pt=1,c,dt;pt<=mxt;pt++) {
			c=t[pt];
			dt=k-n;
			if(!(dt%c)&&(dt>=0)&&f[c]) ans++,f[c]=0;
			n-=c;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
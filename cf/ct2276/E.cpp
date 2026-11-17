#include <iostream>
#define ll long long 
constexpr int N=3e5+5;
using namespace std;
int T,n,lp[4][N],dist[4]={0,2,5,6};
char str[N];
ll d1[N],d2[N],ans[N];
int fnd(int p,int v) {
	p=lp[1][p];
	if(p<=n) p=lp[0][p];
	if(p<=n) p=lp[1][p];
	if(p<=n) p=lp[v-3][p];
	return p;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>str[i];
		for(int j=0;j<=3;j++) lp[j][n+1]=n+1;
		for(int i=n;i;i--) for(int j=0;j<=3;j++) 
			lp[j][i]=(str[i]=='0'+dist[j])?i:lp[j][i+1];
		
		for(int i=0;i<=n+1;i++) d2[i]=0;
		
//		cout<<fnd(1,5)<<" ====\n";
		for(int l=n,r5,r6;l;l--) {
			r5=fnd(l,5);
			r6=fnd(l,6);
//			cout<<r5<<' '<<r6<<'\n';
			if(r5>=r6) {
				d2[n]++,d2[l-1]--,d2[l-1]-=n-l+1;
				if(l>1) d2[l-2]+=n-l+1; 
			}
			else {
				d2[r5-1]++,d2[l-1]--,d2[l-1]-=r5-l;
				if(l>1) d2[l-2]+=r5-l,d2[l-2]+=n-r6+1;
				d2[n]++,d2[r6-1]--,d2[l-1]-=n-r6+1;
			}
//			cout<<d2[n]<<" =====\n";
		}
		ans[n+1]=d1[n+1]=0;
		for(int i=n;i;i--) d1[i]=d2[i]+d1[i+1];
		for(int i=n;i;i--) ans[i]=ans[i+1]+d1[i];
		for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
	}
	return 0;
}

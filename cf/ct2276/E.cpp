#include <iostream>
using namespace std;
constexpr int N=2e5+2;
int T,n,t,ans,p[N<<1],pos[N];
void fm(int i,int j) {
	int x=p[i];
	if(pos[x-1]<j&&pos[x+1]<j) t++;
	if(pos[x-1]>=j&&pos[x+1]>=j) t--;
}
void bm(int j) {
	int x=p[j];
	if(pos[x-1]>j&&pos[x+1]>j) t++;
	if(pos[x-1]<j&&pos[x+1]<j) t--;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>p[i];
			p[n+i]=p[i],pos[p[i]]=0;
		}
		ans=0,pos[n+1]=0;
		t=1,pos[p[1]]=1;
		for(int j=1,i=1;i<n*2;) {
			cout<<j<<' '<<i<<' '<<t<<'\n';
			if(t>2||i-j+1>n) {
				bm(j++);
				pos[p[i]]=i;
			} else {
				pos[p[i]]=i;
				if(i-j+1==n) ans++;
				fm(++i,j);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
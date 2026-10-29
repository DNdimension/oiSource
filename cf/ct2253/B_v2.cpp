#include <iostream>
using namespace std;
constexpr int N=2e5+2;
struct Block {
	int v,l;
} b[N];
int t,ans,f,n,c;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		cin>>b[1].v;
		ans=c=b[1].l=1;
		f=0;
		for(int i=2,x;i<=n;i++) {
			cin>>x;
			if(x==b[c].v) b[c].l++;
			else b[++c]={x,1},++ans;
		}
		for(int i=1;i<c&&!f;i++) {
			if(b[i].l>1&&b[i+1].l>1) f=2;
		}
		for(int i=1;i<=c&&!f;i++) {
			if(b[i].l>1&&b[i].v!=b[max(i-2,1)].v) f=1;
			else if(b[i].l>1&&b[i].v!=b[min(i+2,c)].v) f=1;
		}
		cout<<ans+f<<'\n';
	}
	return 0;
}
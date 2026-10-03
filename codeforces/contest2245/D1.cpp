#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int N=2e5+2,M=1e6+2;
int t,n,m,f,o[N],d[N],a[N];
vector<int> v[N];
queue<int> q;
struct E {
	int o;
	int i,j;
} e[M];
void topo() {
	int cnt=0,i=0;
	for(i=1;i<=n;i++) if(!d[i]) q.push(i);
	while(!q.empty()) {
		i=q.front();
		q.pop();
		a[i]=++cnt;
		for(auto j:v[i]) if(!--d[j]) q.push(j);
	}
	if(cnt!=n) f=0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		f=1;
		for(int k=1;k<=m;k++) {
			cin>>e[k].o>>e[k].i>>e[k].j;
			if(e[k].i==e[k].j) o[e[k].i]=e[k].o;
		}
		for(int k=1,i,j;k<=m;k++) {
			i=e[k].i,j=e[k].j;
			if(i==j) continue;
			if(o[i]==o[j]&&e[k].o!=o[i]) f=0;
			if(e[k].o==2&&o[i]*o[j]==2) {
				if(o[i]==2) { int t=i; i=j; j=t; }
				v[i].push_back(j);
				d[j]++;
			}
			if(e[k].o==1&&o[i]*o[j]==2) {
				if(o[i]==2) { int t=i; i=j; j=t; }
				v[j].push_back(i);
				d[i]++;
			}
		}
		topo();
		if(f) {
			cout<<"YES\n";
			for(int k=1;k<=n;k++) {
				if(o[k]==2) a[k]*=-1;
				cout<<a[k]<<" \n"[k==n];
			}
		} else cout<<"NO\n";
		for(int k=1;k<=n;k++) {
			d[k]=0;
			while(!v[k].empty()) v[k].pop_back();
		}
	}
	return 0;
}
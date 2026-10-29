#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,n,m,ans,a[N],b0[N],m2[N],c,c1,c2;
struct Mons {
	int b,c;
} m1[N];
struct CMP {
	bool operator()(int a,int b) {return a>b;}
};
bool CMP1(Mons a,Mons b) {return (a.b==b.b?a.c>b.c:a.b<b.b);}
bool CMP2(int a,int b) {return a<b;}
priority_queue<int,vector<int>,CMP> Q;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		c=c1=c2=ans=0;
		cin>>n>>m;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			Q.push(x);
		} 
		for(int i=1;i<=m;i++) cin>>b0[i];
		for(int i=1,x;i<=m;i++) {
			cin>>x;
			if(x) m1[++c1]={b0[i],x};
			else m2[++c2]=b0[i]; 
		}
		sort(m1+1,m1+c1+1,CMP1);
		sort(m2+1,m2+c2+1,CMP2);
		for(int i=1;i<=c1&&!Q.empty();) {
			if(Q.top()>=m1[i].b) ++ans,Q.push(max(m1[i++].c,Q.top()));
			else a[++c]=Q.top(); 
			Q.pop();
		}
		for(;!Q.empty();Q.pop()) a[++c]=Q.top();
		for(int i=1,j=1;i<=c&&j<=c2;i++) {
			if(a[i]>=m2[j]) ++ans,j++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

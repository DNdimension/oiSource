#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,n,b[N],ic,num,nc[N],ls[3],rs[3];
bool f;
struct Num {
	int v,p;
} a[N];
bool CMP(Num n1,Num n2) {
	if(n1.v==n2.v) return n1.p<n2.p;
	return n1.v<n2.v;
}
bool ck(int u,int v) {
	bool ret=1;
	swap(b[u],b[v]);
	for(int i=1;i<=n;i++) nc[i]=0;
	for(int i=1;i<=n&&ret;i++) {
		if(nc[b[i]]) ret=0;
		else while(b[i]==b[i+1]) i++;
		nc[b[i]]++;
	}
	swap(b[u],b[v]);
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		ls[0]=f=num=ic=0;
		cin>>n;
		b[n+1]=1e9;
		for(int i=1;i<=n;i++) nc[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i].v,a[i].p=i;
		sort(a+1,a+n+1,CMP);
		for(int i=1;i<=n;i++) {
			if(a[i].v!=a[i-1].v) ++ic;
			b[a[i].p]=ic;
		}
		for(int i=1;i<=n;i++) {
			while(b[i]==b[i+1]) i++;
			nc[b[i]]++;
		}
		for(int i=1;i<=n&&!num;i++) if(nc[i]>1) num=i;
		if(!num) f=1;
		else {
			for(ls[0]=ls[0]+1;b[ls[0]]!=num;) ls[0]++;
			for(rs[0]=ls[0];b[rs[0]+1]==num;) rs[0]++;
			for(ls[1]=rs[0]+1;b[ls[1]]!=num;) ls[1]++;
			for(rs[1]=ls[1];b[rs[1]+1]==num;) rs[1]++;
			if(nc[num]==2) {
				if(ck(ls[0],ls[1]-1)) f=1;
				if(ck(rs[1],rs[0]+1)) f=1;
				if(ls[0]==rs[0]&&rs[1]<n&&ck(ls[0],rs[1]+1)) f=1;
				if(ls[1]==rs[1]&&ls[0]>1&&ck(ls[0]-1,rs[1])) f=1;
				
 			} else {
				for(ls[2]=rs[1]+1;b[ls[2]]!=num;) ls[2]++;
				for(rs[2]=ls[2];b[rs[2]+1]==num;) rs[2]++;
 				if(ls[0]==rs[0]&&ck(ls[0],rs[1]+1)) f=1;
 				if(ls[2]==rs[2]&&ck(rs[2],ls[1]-1)) f=1;
			}
		}
		
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
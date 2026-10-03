#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N=102;
struct M {
	int id,val;
};
struct CMP {
	bool operator()(const M& a,const M& b) {
		return a.val>b.val;
	}
};
int ans,n,Vf[N],Vb[N];
priority_queue<M, vector<M>, CMP>pq;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>Vf[i];
		Vb[i]=Vf[i];
		pq.push({i,Vf[i]});
	}
	Vf[n+1]=Vf[1];
	Vb[0]=Vb[n];
	while(pq.size()-1) {
		n=pq.top().id;
		ans+=Vf[n]*Vb[n-1]*Vf[n+1];
		cout<<pq.top().id<<' '<<Vf[n]<<' '<<ans<<'\n';
		Vf[n-1]=Vf[n];
		Vb[n+1]=Vb[n];
		pq.pop();
	}
//	cout<<ans;
	return 0;
}
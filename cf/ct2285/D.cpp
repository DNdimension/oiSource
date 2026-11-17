#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr ll N=2e5+5,MOD=1e9+7;
int T,n,m,q,df[N];
ll a[N],pre[N],jc[N];
ll mInv(ll a) {
	ll t=1,n=MOD-2;
	for(;n;) {
		if(n&1LL) t=t*a%MOD,n-=1LL;
		else a=a*a%MOD,n>>=1LL;
	}
	return t;
}
struct Query {
	ll p,v,c,i,dif;
} qs[N],qk;

bool cmp(Query q1,Query q2) {
	if(q1.v==q2.v) return q1.p<q2.p;
	return q1.v<q2.v;
}

bool cmpi(Query q1,Query q2) {return q1.i<q2.i;}
bool cmpv(Query q1,Query q2) {return q1.v<q2.v;}
bool cmpp(Query q1,Query q2) {return q1.p<q2.p;}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	jc[0]=1;
	for(int i=1;i<N;i++) jc[i]=i*jc[i-1]%MOD;
	cin>>T;
	while(T--) {
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,p,v;i<=q;i++) {
			cin>>p>>v;
			qs[i]={p,v,0,i,0};
		}
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
		for(int i=1;i<=n;i++) df[i]=0;
		
		sort(qs+1,qs+q+1,cmp);
		
		for(int i=1,up,lw;i<=n;i++) {
			ll dt=pre[i]+pre[n-i]-pre[n];
//			cout<<i<<' '<<dt<<'\n';
			if(!dt) {
				if(i+1<=n-i) df[i+1]++,df[n-i+1]--;
				if(n-i+1<=i) df[n-i+1]++,df[i+1]--;
			}
			
			qk={max(i,n-i)+1,dt,0,0,0};
			lw=lower_bound(qs+1,qs+q+1,qk,cmpv)-qs;
			up=upper_bound(qs+1,qs+q+1,qk,cmpv)-qs;
			lw=lower_bound(qs+lw,qs+up,qk,cmpp)-qs;
			if(lw<up) qs[lw].dif++,qs[up].dif--;
			
			dt*=-1;
			qk={min(i,n-i),dt,0,0,0};
			lw=lower_bound(qs+1,qs+q+1,qk,cmpv)-qs;
			up=upper_bound(qs+1,qs+q+1,qk,cmpv)-qs;
			up=upper_bound(qs+lw,qs+up,qk,cmpp)-qs;
			if(lw<up) qs[lw].dif++,qs[up].dif--;
			
		}
		
		for(int i=1;i<=q;i++) qs[i].c=qs[i-1].c+qs[i].dif;
		sort(qs+1,qs+q+1,cmpp);
		for(int i=1,j=1;j<=q;i++) {
			df[i]+=df[i-1];
			while(j<=q&&qs[j].p<i) j++;
			while(j<=q&&qs[j].p==i) qs[j++].c+=df[i];
		}
		sort(qs+1,qs+q+1,cmpi);
//		cout<<'\n';
		for(int i=1,k;i<=q;i++) {
			k=qs[i].c;
			if(k<m) cout<<'0';
//			else cout<<1LL*jc[k-1]*mInv(jc[m-1])%MOD*mInv(jc[k-m])%MOD<<' '<<k;
			else cout<<1LL*jc[k-1]*mInv(jc[m-1])%MOD*mInv(jc[k-m])%MOD;
			cout<<'\n';
		}
		
	}
	return 0;
}

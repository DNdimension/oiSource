#include <cstdio>
#define ll long long 
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
constexpr int N=1e5+2;
ll R,l1,r1,l2,r2,nl,nr;
int L,k,X[N];
bool f;
inline int read() {
	int x=0,F=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') F=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') {
		x=c-'0'+(x<<3)+(x<<1);
		c=getchar();
	}
	return x*F;
}
int ck(ll m) {
	if(m<=0) return -1;
	ll r=0,rk=0;
	for(int i=1;i<=L;i++) {
		if(X[i]>=0) r+=1LL*X[i];
		else r=max(0,r+1LL*X[i]);
		if(r>=m) r=0,rk++;
	}
	return rk;
}
int main() {
	f=1;
	L=read();
	k=read();
	for(int i=1;i<=L;i++) { //multiUse nl
		X[i]=read();
		if(X[i]<0) R=max(R,nl);
		nl=max(0,nl+X[i]);
	}
	if(L<k||k<=0) f=0;	
	l1=l2=1LL;
	r1=r2=max(nl,R);
	
	for(ll m;l1+1LL<r1&&f;) {
		m=l1+r1>>1LL;
		nl=ck(m); //multiUse nl
		if(nl>k) l1=l2=m+1LL;
		else if(nl<k) r1=r2=m-1LL;
		else r1=m;
	}
	if(l1==r1) {
		if(ck(l1)==k) nl=l1;
		else f=0;
	} else if(ck(l1)==k) nl=l1;
	else if(ck(r1)==k) nl=r1;
	else f=0;

	for(ll m;l2+1LL<r2&&f;) {
		m=l2+r2>>1LL;
		nr=ck(m);
		if(nr>k) l2=m+1LL;
		else if(nr<k) r2=m-1LL;
		else l2=m;
	}
	if(l2==r2) {
		if(ck(l2)==k) nr=r2;
		else f=0;
	} else if(ck(r2)==k) nr=r2;
	else if(ck(l2)==k) nr=l2;
	else f=0;
	if(f) printf("%lld %lld",nl,nr);
	else printf("-1");
	return 0;
}
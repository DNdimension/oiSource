#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
struct Num {
	int val,pos;
} num[N];
int T,n,x,y,d;
bool f;
bool CMP(struct Num n1,struct Num n2) {
	return n1.val<n2.val;
}
int main() {
	cin>>T;
	while(T--) {
		cin>>n>>x>>y;
		for(int i=1;i<=n;i++) cin>>num[i].val,num[i].pos=i;
		if(x<y) { x^=y;y^=x;x^=y; }
		d=y,f=1;
		for(int p=1,q=1,dt=p*x-q*y;dt;dt=p*x-q*y) {
			if(dt>0) d=min(d,dt),q++;
			if(dt<0) d=min(d,-dt),p++;
		}
		sort(num+1,num+n+1,CMP);
		for(int i=1;i<=n&&f;i++) {
			if((i-num[i].pos)%d) f=0;
		}
		cout<<(f?"YES":"NO")<<'\n';
		
	}
	return 0;
}
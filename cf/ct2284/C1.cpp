#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+3;
int T,n,k,bs,c,p[N],b[N];
bool np[N];
struct Num {
	int i,v;
} a[N];
bool CMP(Num n1,Num n2) {
	return n1.v<n2.v;
}
void sie(int a) {
	for(int i=2;i<=a;i++) {
		if(!np[i]) p[++c]=i;
		for(int j=1;j<=c&&p[j]*i<=a;j++) {
			np[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	sie(N-2);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			a[i]={i,x};
		}
		sort(a+1,a+n+1,CMP);
		for(int i=1,j=1;i<=n;i++) {
			while(a[i].v>p[j]) j++;
			b[a[i].i]=p[j];
		}
		for(int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
	}
	return 0;
}
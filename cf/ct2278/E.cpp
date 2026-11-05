#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr int N=2e5+2;
int T,n,c0,c1,c2,c3,c4,a[N],b[N],c[N],d[N],e[N];
ll s;
bool CMP(int n1,int n2) {return n1<n2;}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		s=0;
		c1=c2=c3=c4=0;
		for(int i=1;i<=n;i++) cin>>a[i],s+=abs(a[i]);
		for(int i=1;i<=n;i+=2) {
			if(a[i]<0) b[++c1]=-a[i];
			else d[++c3]=a[i];
		}
		for(int i=2;i<=n;i+=2) {
			if(a[i]<0) c[++c2]=-a[i];
			else e[++c4]=a[i];
		}
		sort(b+1,b+c1+1,CMP);
		sort(c+1,c+c2+1,CMP);
		sort(d+1,d+c3+1,CMP);
		sort(e+1,e+c4+1,CMP);
		c0=abs(c1-c2);
		if(c1>c2) {
			for(int i=1,j=1;c0;c0--) {
				if(j<=c4&&e[j]<b[i]) s-=2LL*e[j++];
				else s-=2LL*b[i++];
			}
			
		} else {
			for(int i=1,j=1;c0;c0--) {
				if(j<=c3&&d[j]<c[i]) s-=2LL*d[j++];
				else s-=2LL*c[i++];
			}
			
		}
		cout<<s<<'\n';
	}
	return 0;
}
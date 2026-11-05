#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
constexpr int N=2e5+2;
int T,n,a[N];
ll c,op;
bool CMP(int n1,int n2) {return n1<n2;}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		c=op=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,CMP);
		for(int i=1,j=n,dt;i<j;) {
			if(a[i]==a[i+1]) i++;
			else if(a[j]==a[j-1]) j--;
			else {
				if(i<n-j+1) {
					dt=a[i+1]-a[i];
					c+=1LL*dt*i;
					op+=1LL*dt;
					a[i]=a[i+1];
				}
				else {
					dt=a[j]-a[j-1];
					c+=1LL*dt*(n-j+1);
					op+=1LL*dt;
					a[j]=a[j-1];
				}
			}
		} 
		cout<<c<<' '<<op<<'\n';
	}
	return 0;
}
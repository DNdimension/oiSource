#include <iostream>
#define ll long long 
using namespace std;
constexpr int N=5e5+5;
int n,c;
ll pre[N],ans;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>pre[i];
		pre[i]+=pre[i-1];
	}
	for(int i=1;i<n;i++) {
		if(pre[i]*3==pre[n]*2) ans+=c;
		if(pre[i]*3==pre[n]) ++c;
	}
	cout<<ans<<'\n';
	return 0;
}

#include <iostream>
#include <algorithm>
#define ll unsigned long long 
using namespace std;
constexpr int N=1e2+2;
int T,n,a[N];
ll s1,s2;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		s1=s2=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=n;i;i--) {
			if(s1>s2) s2+=(1ULL<<a[i]);
			else s1+=(1ULL<<a[i]);
		}
//		cout<<s1<<' '<<s2<<'\n';
		cout<<s1*s2<<'\n';
//		cout<<(s1+s2+1ULL)/2ULL*(s1+s2)/2ULL<<'\n';
	}
	return 0;
}
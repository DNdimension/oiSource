#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=2e5+2;
int T,n,ans,arr[N];
bool CMP(int a,int b) {
	return a<b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>arr[i];
		sort(arr+1,arr+n+1,CMP);
		for(int i=1;i<=n&&!ans;) {
			if(arr[i]<n-i+1) ans=n-i+1;
			do {i++;}
			while(i<=n&&arr[i]==arr[i-1]);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
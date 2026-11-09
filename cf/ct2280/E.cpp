#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long 
using namespace std;
constexpr int N=5e5+2;
int T,n,k,arr[N];
ll s[N],ans,c;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>arr[i];
		sort(arr+1,arr+n+1);
		s[n]=0;
		for(int i=n-1;~i;i--) s[i]=s[i+1]+arr[i];
		ans=1e18;
		for(int j=n-1,i=min((int)sqrt(k-1),arr[n-1]);~i;i--) {
			while(j&&arr[j]>i) j--;
			c=s[j+1]-1LL*i*(n-1-j);
			if(i) c+=max(0,arr[n]-(k-1)/i);
			ans=min(ans,c);
		}
		cout<<ans<<'\n';
	}
}


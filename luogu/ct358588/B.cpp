#include <iostream>
#define ll unsigned long long 
using namespace std;
constexpr int N=2e6+2,LOGV=30;
int n,arr[N],t[N];
ll ans;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int p=0,k=1,cnt;p<=LOGV;p++,k<<=1) {
		for(int l=1,m,r=1;r<=n;) {
			if(arr[r]&k) {
				while((arr[r]&k)&&r<=n) r++;
				ans+=1ULL*k*(1LL*(r-1-l+1)*(r-1+l)>>1ULL);
				l=r;
			} else {
				cnt=0,m=l;
				while(!(arr[r]&k)&&r<=n) {
					if(arr[r]<k&&arr[r]<=n) {
						if(!t[arr[r]]++) cnt+=cnt<k;
					}
					while(r-m+1>k){
						if(arr[m]<k&&arr[m]<=n) {
							if(t[arr[m]]<=1) {
								break;
							}
							t[arr[m]]--;
							m++;
						} else m++;
					}
					if(cnt==k) ans+=1ULL*k*(m-l+1);
					r++;
				}
				r--;
				ans+=1ULL*k*(l-1)*(r-l+1);
				while(l<=r) {
					if(arr[l]<=n) t[arr[l]]=0;
					l++;
				}
				r++;
			}		
		}
	}
	cout<<ans<<'\n';
	return 0;
}
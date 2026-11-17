#include <iostream>
#include <queue>
using namespace std;
constexpr int N=4e5+4;
int T,n,k,ans,a[N],p[N];
char ch;
deque<int> Q;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>k;
		while(!Q.empty()) Q.pop_back();
		for(int i=1,v=0,c=0;i<=n;i++) {
			cin>>ch;
			if(ch=='(') v++;
			else {
				a[++c]=v;
				v=0;
			}
		}
		n>>=1,ans=0;
		for(int i=1,A=0;i<=n;i++) {
			A+=a[i];
			if(i-1<=k) ans=max(ans,min(n,A+k-i+1));
		}
		for(int i=1;i<=n;i++) {
			a[i]--;
			p[i]=p[i-1]+a[i];
		}
		for(int i=1;i<=n;i++) {
			while(!Q.empty()&&i-1-Q.front()>k) Q.pop_front();
			while(!Q.empty()&&p[i-1]<p[Q.back()]) Q.pop_back();
			Q.push_back(i-1);
			ans=max(ans,p[i]-p[Q.front()]+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

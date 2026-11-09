#include <iostream>
using namespace std;
constexpr int N=1e2+2;
int T,n,k,ca[2],cb[2];
bool f;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>T;
	while(T--) {
		ca[0]=ca[1]=cb[0]=cb[1]=0;
		cin>>n>>k;
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			ca[x&1]++;
		}
		for(int i=1,x;i<=n;i++) {
			cin>>x;
			cb[x&1]++;
		}
		f=(k&1&&ca[1]<=cb[1])||(k&1^1&&ca[0]<=cb[0]);
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
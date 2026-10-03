#include <iostream>
using namespace std;
int n,t;
void solve(int t,int k) {
	if(t<=9) {
		cout<<((k&1)?"S\n":"M\n");
		return;
	}
	int tt=0;
	for(;t;t/=10) tt+=t%10;
	solve(tt,k^1);
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>t;
		solve(t,0);
	}
	return 0;
}
#include <iostream>
using namespace std;
int a,b,T;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>a>>b;
		cout<<((a>b)?min(b,(a-b)):(-1))<<'\n';
	}
	return 0;
}
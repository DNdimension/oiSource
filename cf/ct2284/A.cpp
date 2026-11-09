#include <iostream>
using namespace std;
int T,n;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		cout<<n*n/4<<'\n';
	}
	return 0;
}
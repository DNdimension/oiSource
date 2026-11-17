#include <iostream>
using namespace std;
int a,b,c,T;
int main() {
	cin>>T;
	while(T--) {
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		if(a>c) swap(a,c);
		if(b>c) swap(b,c);
		if(c-b==1&&b-a==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}

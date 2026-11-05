#include <iostream>
using namespace std;
int a,b,c,T;
char ch;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>a>>b>>c;
		if(a>=b&&a>=c) ch='P';
		if(b>=a&&b>=c) ch='R';
		if(c>=a&&c>=b) ch='S';
		for(int i=1;i<=a+b+c;i++) cout<<ch;
		cout<<'\n';
		
	}
	return 0;
}
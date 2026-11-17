#include <iostream>
using namespace std;
int T,f1,f0;
string s;
int main() {
	cin>>T;
	while(T--) {
		cin>>s;
		f1=f0=1;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='1'&&f1) f1=0;
			else if(s[i]=='0'&&f0) f0=0;
			else cout<<s[i];
		}
		cout<<'\n';
	}
	return 0;
}


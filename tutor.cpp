#include <iostream>
using namespace std;
string s;
int n;
bool f;
int main() {
	cin>>s;
	n=s.size(),f=1;
	for(int i=0;i<n;i++) if(s[i]!=s[n-1-i]) f=0;
	if(f) cout<<"yes\n";
	else cout<<"no\n";
	return 0;
}

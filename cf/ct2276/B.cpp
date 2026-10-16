#include <iostream>
#include <string>
using namespace std;
const int N=3e5+2;
int a,b,n,T,ans;
string s;
bool f,g,s1[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>s;
		f=g=1;
		n=s.size(),ans=0;
		for(int i=0;i<n;i++) s1[i]=s[i]-'0';
		for(int i=1;i<n-1;i++) {
			if(s1[i]!=s1[i-1]&&s1[i]!=s1[i+1]&&f) {
				ans++;
				f=0;
			}
			if(s1[i]==s1[i-1]&&s1[i]==s1[i+1]&&g) {
				ans++;
				g=0;
			}
		}
		cout<<ans+1<<'\n';
	}
	return 0;
}
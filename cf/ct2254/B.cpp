#include <iostream>
using namespace std;
constexpr int N=2e5+2;
char ch[N];
int T,n,c,f;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		c=0,f=1;
		for(int i=1;i<=n;i++) cin>>ch[i];
		for(int i=2;i<n&&f;i++) {
			if(ch[i-1]==ch[i+1]&&ch[i-1]!=ch[i]) ch[i]=ch[i-1],f=0;
		}
		for(int i=2;i<n&&f;i++) {
			if(ch[i]!=ch[i-1]&&ch[i]!=ch[i+1]) {
				c--;
				break;
			}
		}
		for(int i=1;i<=n;i++) {
			if(ch[i]!=ch[i-1]) c++;
		}
		cout<<c<<'\n';
	}
	return 0;
}
#include <iostream>
using namespace std;
int T,n,m,c1[26],c2[26];
char ch;
bool f[3],g;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		f[0]=f[1]=f[2]=0,g=1;
		for(int i=0;i<26;i++) c1[i]=c2[i]=0;
		for(int i=0;i<n;i++) {
			cin>>ch;
			c1[ch-'a']++;
		}
		for(int i=0;i<m;i++) {
			cin>>ch;
			c2[ch-'a']++;
		}
		for(int i=0;i<26&&g;i++) {
			c1[i]-=c2[i];
			if(i=='s'-'a') f[0]=(c1[i]==1);
			else if(i=='i'-'a') f[1]=(c1[i]==1);
			else if(i=='x'-'a') f[2]=(c1[i]==1);
			else g=(c1[i]==0);
		}
		if(f[0]&f[1]&f[2]&g) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
#include <iostream>
using namespace std;
constexpr int N=1e6+2;
string s1,s2;
int nxt[N],f[N];
void build() {
	nxt[0]=-1;
	for(int i=0,t=nxt[0];i<s2.size();) {
		if(t<0||s2[i]==s2[t]) {
			t++;
			nxt[i+1]=t;
			i++;
		} 
		else t=nxt[t];
	}
}
int main() {
	cin>>s1>>s2;
	build();
	for(int i=0,j=0;i<s1.size();) {
		if(j<0||s1[i]==s2[j]) i++,j++;
		else j=nxt[j];
		if(j==s2.size()) {
			cout<<i-j+1<<'\n';
			j=nxt[j];
		}
	}
	for(int i=1;i<=s2.size();i++) cout<<nxt[i]<<' ';
	return 0;
}
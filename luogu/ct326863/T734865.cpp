#include <iostream>
using namespace std;
const int N=1e4+2;
int n,m;
char ch;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(!n||!m) cout<<1;
	else {
		cin>>ch>>ch>>ch;
		if(ch=='B') cout<<2;
		else cout<<1;
	}
}
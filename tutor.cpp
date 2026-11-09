#include <iostream>
using namespace std;
constexpr int N=2e7+4;
int n,c,p[N];
bool np[N];
void sie(int n) {
	for(int i=2;i<=n;i++) {
		if(!np[i]) p[++c]=i;
		for(int j=1;j<=c;j++) {
			if(p[j]*i>n) break;
			np[p[j]*i]=1;
			if(i%p[j]==0) break; 
		}
	}
}
int main() {
	cin>>n;
	sie(n);
//	for(int i=1;i<=c;i++) cout<<p[i]<<" \n"[i==n];
	for(int i=1;i<=c;i++) {
		if(p[i]-p[i-1]>90) cout<<p[i]<<'\n';
	}
	return 0;
}

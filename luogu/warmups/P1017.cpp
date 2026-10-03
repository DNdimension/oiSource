#include <iostream>
using namespace std;

int r,k,n;
char ans[20];
char d[]="0123456789ABCDEFGHIJ";
int main() {
	cin>>k>>r;
	cout<<k<<'=';
	for(;k;) {
		if(k%r<0) {
			ans[++n]=d[-r+k%r];
			k=(k+r-k%r)/r;
		}
		else {
			ans[++n]=d[k%r];
			k=(k-k%r)/r;
		}
	}
	for(;n;n--) cout<<ans[n];
	cout<<"(base"<<r<<")";
	return 0;
	
}
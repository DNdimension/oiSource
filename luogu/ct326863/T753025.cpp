#include <iostream>
#define lli long long int
using namespace std;
inline int read() {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int n,a1,a2;
lli l1,l2,t;
int main() {
	n=read();
	l1=a1=read();
	for(;n>1;n--) {
		a2=a1;
		a1=read();
		t=min(l1+1LL*a1,l2+1LL*min(a1,a2));
		l2=l1;
		l1=t;
	}
	cout<<l1;
	return 0;
}
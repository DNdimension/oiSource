#include <iostream>
#include <bitset>
#define N 101
using namespace std;

int a[N],n;
int s=0;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[0]+=a[i];
	}
	a[0]/=n;
	for(int i=1;i<n;i++) {
		if(a[i]==a[0]) continue;
		s++;
		a[i+1]+=a[i]-a[0];
		a[i]-=a[i]-a[0];
	}
	cout<<s<<'\n';
	return 0;
}
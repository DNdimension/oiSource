#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int f,t,n,k,a[N],r[N];
int req_OR(int i,int j) {
	printf("? or %d %d\n",i,j);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}
int req_AND(int i,int j) {
	printf("? and %d %d\n",i,j);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}
void rep() {
	printf("!");
	for(int i=1;i<=n;i++) printf(" %d",a[i]);
}
int main() {
	scanf("%d%d",&n,&k);
	f=1;
	t=0;
	for(int i=2;i<=n;i++) {
		r[i]=req_OR(1,i);
		if(!(r[i]&1)) f=0;
	}
	if(f) {
		a[1]=1;
		for(int i=2;i<=n;i++) if(r[i]==1) t=i;
		for(int i=2;i<=n;i++) {
			if(i==t) continue;
			if(i<t) a[i]=req_OR(i,t);
			else a[i]=req_OR(t,i);
		}
	} 
	else for(int i=2;i<=n;i++) a[i]=r[i];
	rep();
	return 0;
}
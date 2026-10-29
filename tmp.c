#include <stdio.h>
int ans[100];
long long cnt,n,nn=0;
int main() {
	scanf("%lld",&n);
	for(int x=n;x;x/=10,nn*=10) nn+=x%10;
	nn/=10;
	printf("%lld\n",nn);
	for(;nn;nn/=7) ans[++cnt]=nn%7;
//	while(!ans[cnt]&&cnt) cnt--;
	for(;cnt;cnt--) printf("%d",ans[cnt]);
	return 0;
}
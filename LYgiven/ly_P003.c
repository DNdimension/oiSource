#include <stdio.h>
#define N 10002
int q,c,m,n[N],ans[N],f[N*2];
int main() {
	scanf("%d",&q);
	for(int i=1;i<=q;i++) {
		scanf("%d",&n[i]);
		if(n[i]>m) m=n[i];
	}
	f[0]=1;
	for(int i=0,j=1,h=1;i<m;j++) {
		if(j>=h) h*=10;
		if(f[j%(h/10)]&&j/(h/10)!=7) f[j]=1;
		if(f[j]&&j%7!=0) ans[++i]=j;
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[n[i]]);
	return 0;
}
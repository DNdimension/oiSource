#include <stdio.h>
double ans,h;
int main() {
	scanf("%lf",&h);
	ans=h;
	h/=2.0;
	for(int i=2;i<=10;i++,h/=2.0) ans+=h*2;
	printf("%g\n%g",ans,h);
	return 0;
}
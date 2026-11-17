#include <stdio.h> 
int x,y;
void swap(int *x,int *y) {
	int a=*x;
	*x=*y;
	*y=a;
}
int gcd(int x,int y) {
	if(x<y) swap(&x,&y);
	for(;y;swap(&x,&y)) x%=y;
	return x; 
}
int lcm(int x,int y) {
	int w=gcd(x,y);
	w*=(x/w)*(y/w);
	return w;
}
int main() {
	scanf("%d %d",&x,&y);
//	swap(&x,&y);
//	printf("%d %d",x,y);
	printf("%d\n%d",gcd(x,y),lcm(x,y));
	
	return 0;
}

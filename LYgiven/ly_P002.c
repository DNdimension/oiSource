#include<stdio.h>
unsigned T,a,b,c,sum,t;
int main() {
	scanf("%u",&T);
	while(T--) {
		scanf("%u%u%u",&a,&b,&c);
		for(sum=0,t=(a|b)&(~c);t;t>>=1u) sum+=t&1;
		printf("%u %u\n",(a|b)&(~c),sum);	
	}
	return 0;
}
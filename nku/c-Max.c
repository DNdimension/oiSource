#include <stdio.h>
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a<b) a=b;
	if(a<c) a=c;
	printf("%d",a);
	return 0;
}
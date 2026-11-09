#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 102
char s[N];
int n;
int main() {
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) {
		if('a'<=s[i]&&s[i]<='z') s[i]=s[i]-'a'+'A';
	}
	printf("%s\n",s);
	return 0;
}

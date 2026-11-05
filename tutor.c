#include <stdio.h>
#include <string.h>
char s[32];
int f,t[32];
int main() {
	f=1;
	scanf("%s",&s);
	for(int i=0;i<strlen(s)&&f;i++) {
		if(s[i]<='Z') s[i]=s[i]-'A'+'a';
		if(s[i]<'a'||s[i]>'z') f=0;
		else t[i]=s[i]-'a'+1;
	}
	if(f) for(int i=0;i<strlen(s);i++) printf("%d",t[i]);
	else printf("Wrong Format");
	return 0;
}
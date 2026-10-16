#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int a,b,c,d,e,s;
	cin>>a>>b>>c>>d>>e;
	s=a+b+c+d+e;
	a=a/3;
	e=e+a,b=b+a;
	b=b/3;
	a=a+b,c=c+b;
	c=c/3;
	b=b+c,d=d+c;
	d=d/3;
	c=c+d,e=e+d;
	e=e/3;
	d=d+e,a=a+e;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
	cout<<s-a-b-c-d-e;
    return 0;
}
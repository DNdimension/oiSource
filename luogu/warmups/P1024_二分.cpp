#define f(x) (a*(x)*(x)*(x)+b*(x)*(x)+c*(x)+d)
#define eps 1e-8
#include <iostream>
#include <iomanip>
using namespace std;
double a,b,c,d;
double gt(double le,double ri) {
	double mid = (le+ri)/2.00;
	if(le-ri<eps&&le-ri>-eps) return mid;
	if(f(mid)*f(le)<-eps) return gt(le,mid);
	else return gt(mid,ri);
}

int main() {
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++) {
		if(f(i)>-eps&&f(i)<eps) cout<<fixed<<setprecision(2)<<(double)(i)<<' ';
		else if(f(i)*f(i+1)<-eps) cout<<fixed<<setprecision(2)<<gt(i,i+1)<<' ';
	}
	return 0;
}
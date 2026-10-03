#define f(x) (a*(x)*(x)*(x)+b*(x)*(x)+c*(x)+d)
#define g(m,n) ((m)*f(n)-(n)*f(m))/(f(n)-f(m))
#define eps 1e-8
#include <iostream>
#include <iomanip>
using namespace std;
double a,b,c,d;

int main() {
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++) {
//		cout<<i<<'\n';
		if(f(i)>-eps&&f(i)<eps) cout<<fixed<<setprecision(2)<<(double)(i)<<' ';
		else if(f(i)*f(i+1)<-eps) {
			double l=i,r=i+1,t;
			while(l-r>eps||l-r<-eps) {
				t=(l+r)/2.00;
				if(f(t)*f(l)<-eps) r=t;
				else l=t;
			}
			cout<<fixed<<setprecision(2)<<l<<' ';
		}
	}
	return 0;
}
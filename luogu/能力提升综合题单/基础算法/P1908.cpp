#include <iostream>
#define ll long long
using namespace std;
const int N=5e5+2;
int n,a[N],aa[N];
ll f(int L,int R) {
    if(L==R) return 0;
    int m=L+R>>1;
    ll c=f(L,m)+f(m+1,R);
    int t1=m-L,t2=R-(m+1);
    while(~t1&&~t2) {
        if(a[t1+L]>a[t2+m+1]) {
            aa[L+1+t1+t2]=a[L+t1];
            t1--;
            c+=t2+1LL;
        } else {
            aa[L+1+t1+t2]=a[m+1+t2];
            t2--;
        }
    }
    for(;~t1;t1--) aa[L+t1]=a[L+t1];
    for(;~t2;t2--) aa[L+t2]=a[m+1+t2];
    for(;R>=L;L++) a[L]=aa[L];
    return c;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<f(1,n)<<'\n';
    // for(int i=1;i<=n;i++) cout<<aa[i]<<' ';
	return 0;
}
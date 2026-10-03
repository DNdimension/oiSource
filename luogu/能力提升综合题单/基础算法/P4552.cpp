#include <iostream>
using namespace std;
const int N=1e5+2;
int n;
long long a[N],ns,ps;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>1;i--) {
        a[i]-=a[i-1];
        if(a[i]>0) ps+=a[i];
        else ns+=a[i];
    }
    cout<<max(-ns,ps)<<'\n'<<abs(ns+ps)+1;
    return 0;
}
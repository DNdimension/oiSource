#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N=1e5+2;
int n,a[N],d[N],ans1,ans2;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>a[++n]) {}
    n-=1;
    ans1=1,d[1]=a[1];
    for(int i=2,di;i<=n;i++) {
        di=upper_bound(d+1,d+ans1+1,a[i],[](int val,int d_val){
            return d_val<val;
        })-d;
        d[di]=a[i];
        ans1=max(ans1,di);
    }
    cout<<ans1<<'\n';
    memset(d,0,sizeof(d));
    d[1]=a[1];
    ans2=1;
    for(int i=2,di;i<=n;i++) {
        
    }
    return 0;
}
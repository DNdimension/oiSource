#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[] = {9,7,5,3,1};
    int i=upper_bound(a,a+5,4,[](int v,int e){
        return v<e;
    })-a;
    cout<<i<<'\n';
    return 0;
}
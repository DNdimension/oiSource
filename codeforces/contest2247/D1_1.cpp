#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=1e6+2;
int t,n,q,k;
struct Num {
	int val,pos;
} num[N];
bool cmp(struct Num num1,struct Num num2) {
	if(num1.val==num2.val) return num1.pos<num2.pos;
	return num1.val<num2.val;
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>q;
		k=0;
		for(int i=0;i<n;i++) {
			cin>>num[i].val;
			num[i].pos=i;
		}
		sort(num,num+n,cmp);
		for(int i=0,j,l,m;i<n;i++) {
			if(num[i].pos>i) {
				for(j=i,l=num[i].pos,m=1;l;m<<=1) {
					if((j&m)^(l&m)) k=max(k,m);
					l^=(l&m);
				}
			}
		}
		cout<<k<<'\n';
		
	}
	return 0;
}
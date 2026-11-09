#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=1e5+2,V=2e5+4;
int T,c,ans[N],arr[N],p[N],dp[V];
bool np[V];
struct Q {
	int a,b,i;
} q[N],q1[N];
bool CMP(Q q1,Q q2) { return q1.a<q2.a; }
void sie(int n) {
	for(int i=2;i<=n;i++) {
		if(!np[i]) p[++c]=i;
		for(int j=1;j<=c;j++) {
			if(p[j]*i>n) break;
			np[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
int gcd(int a,int b) {
	if(a<b) swap(a,b);
	while(b) {
		a%=b;
		swap(a,b);
	} return a;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	sie(V-2);
	for(int i=1,a,b;i<=T;i++) {
		cin>>a>>b;
		q1[i]=q[i]={a,b,i};
	}
	sort(q1+1,q1+T+1,CMP);
	for(int i=1,j=1;i<=T;i++) {
		while(p[j]<=q1[i].a) j++;
		for(int k=j;k<=c&&p[k]<q1[i].b;k++) if(q1[i].b%p[k]) {
			ans[q1[i].i]=p[k];
			break;
		}
	}
	for(int i=1,a,b;i<=T;i++) {
		a=q[i].a,b=q[i].b;
		if(a==b) cout<<"0\n";
		else if(gcd(a,b)==1) cout<<"1\n"<<b-a<<'\n';
		else if(ans[i]) cout<<"2\n"<<ans[i]-a<<' '<<b-ans[i]<<'\n';
		else {
			arr[0]=a;
			for(int i=a+1;i<=b;i++) {
				if(gcd(a,i)==1) dp[i]=1,arr[1]=i;
				else dp[i]=1e6;
			}
			for(int i=a+2;i<=b;i++) {
				for(int j=a+1;j<i;j++) {
					if(gcd(j,i)==1&&dp[j]+1<dp[i]) {
						dp[i]=dp[j]+1;
						arr[dp[j]]=j,arr[dp[i]]=i;
					}
				}
			}
			cout<<dp[b]<<'\n';
			for(int i=1;i<=dp[b];i++) {
				cout<<arr[i]-arr[i-1]<<" \n"[i==dp[b]];
			}
			
		}
	}
	return 0;
}
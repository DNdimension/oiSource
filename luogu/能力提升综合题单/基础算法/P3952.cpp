#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
int t,L,l,r,M,cur,cnt;
string R,ls,rs;
char c,C[101];
bitset<26> f;
bitset<101> g,h;
string F(int n) {
    if(!n) return "O(1)";
    string ret="";
    for(;n;n/=10) ret+='0'+n%10;
    reverse(ret.begin(),ret.end());
    return ret;
}
int main() {
    cin>>t;
    for(;t;t--) {
        cin>>L>>R;
        cnt=M=cur=0;
        f.reset();
        g.reset();
        for(;L;L--) {
            cin>>c;
            if(c=='F') {
                cin>>c>>ls>>rs;
                if(f[c-'a']) M=1e7;
                f[c-'a']=1;
                C[++cnt]=c;
                if(ls=="n") l='n';
                else l=stoi(ls);
                if(rs=="n") r='n';
                else r=stoi(rs);
                if(l>r) g[cnt]=1;
                if(l!=r&&r>100&&!g.any()) cur++,h[cnt]=1;
                M=max(M,cur);
            }

            if(c=='E'&&cnt>=0) { //ensure no RE
                if(h[cnt]) cur--;
                h[cnt]=g[cnt]=0;
                f[C[cnt--]-'a']=0;
            }
        }
        if(cur||cnt||M==1e7) cout<<"ERR\n";
        else {
            if(M&&R=="O(n^"+F(M)+")") cout<<"Yes\n";
            else if(!M&&R=="O(1)") cout<<"Yes\n";
            else cout<<"No\n";
        } 
    }
    return 0; 
}
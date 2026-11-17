#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	int m = n / 2;
	vector<int> c;
	c.push_back(0);
	
	int run = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') run++;
		else {
			c.push_back(run);
			run = 0;
		}
	}
	
	int mx = 0, cur = 0;
	for(int i = 1; i <= m; i++) {
		cur += c[i];
		if(i - 1 <= k) mx = max(mx, min(m, cur + k - (i - 1)));
	}
	
	vector<int> a(m + 1), pre(m + 1);
	for(int i = 1; i <= m; i++) {
		a[i] = c[i] - 1;
		pre[i] = pre[i - 1] + a[i];
	}
	
	deque<int> dq;
	for(int y = 1; y <= m; y++) {
		int x = y - 1;
		while(!dq.empty() && pre[dq.back()] >= pre[x]) dq.pop_back();
		dq.push_back(x);
		while(!dq.empty() && dq.front() < y - (k + 1)) dq.pop_front();
		mx = max(mx, min(m, pre[y] - pre[dq.front()] + 1));
	}
	
	cout << mx << "\n";
}

signed main() {
	int t;
	cin >> t;
	while(t--) solve();
}

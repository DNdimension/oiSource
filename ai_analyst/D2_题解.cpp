#include <bits/stdc++.h>
#include <cassert>

using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    int N = 1;
    while (N < n) N *= 2;
    while (n < N) {
        a.pb(1e9);
        n++;
    }
    vector<array<int, 3>> t(2 * n);
    vector<int> L(2 * n, 1);
    for (int j = 0; j < n; j++) t[n + j] = {a[j], a[j], 0};
    auto pull= [&](int j, int len) {
        t[j][0] = min(t[j << 1][0], t[j << 1 | 1][0]);
        t[j][1] = max(t[j << 1][1], t[j << 1 | 1][1]);
        t[j][2] = max(t[j<<1][2], t[j<<1|1][2]);
        if (t[j<<1][1] > t[j<<1|1][0]) t[j][2] = max(t[j][2], len / 2);
    };
    for (int j = n - 1; j >= 1; j--) {
        L[j] = 2 * L[j << 1];
        pull(j, L[j]);
    }
    cout << t[1][2] << '\n';
    while (q--) {
        int p, x; cin >> p >> x;
        p += n;
        t[p] = {x, x, 0};
        p >>= 1;
        int len = 2;
        while (p) {
            pull(p, len);
            p >>= 1;
            len *= 2;
        }
        cout << t[1][2] << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
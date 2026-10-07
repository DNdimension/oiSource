#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int seed = (argc > 1) ? atoi(argv[1]) : 0;
    mt19937 rng(seed);

    int maxT = 10;
    int maxN = 1e3;
    int maxQ = 1e3;
    int maxVal = 1e3;

    int T = rng() % maxT + 1;
    cout << T << '\n';
    for (int tc = 0; tc < T; tc++) {
        int n = rng() % maxN + 1;
        int q = rng() % maxQ + 1;
        cout << n << ' ' << q << '\n';
        for (int i = 0; i < n; i++) {
            cout << (int)(rng() % maxVal + 1) << " \n"[i + 1 == n];
        }
        for (int i = 0; i < q; i++) {
            int p = rng() % n;                     // 0-indexed
            int x = rng() % maxVal + 1;
            cout << p << ' ' << x << '\n';
        }
    }
    return 0;
}
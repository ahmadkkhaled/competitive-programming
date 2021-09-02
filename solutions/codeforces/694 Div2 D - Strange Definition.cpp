#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sof(v) (int)v.size()

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};

const double PI = acos(-1.0);
const int MXN = 3e5 + 7;

int a[MXN];

int get(int x) {
    int ret = 1;
    for (int p = 2; p * p <= x; p++) {
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        if (cnt & 1)
            ret *= p;
    }
    if (x != 1)
        ret *= x;
    return ret;
}

void run_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> frq;
    for (int i = 0; i < n; i++) {
        frq[get(a[i])]++;
    }

    int ans[2] = {-1, -1};
    for (auto pr : frq)
        ans[0] = max(ans[0], pr.second);

    for (auto pr : frq) {
        if (pr.first == 1)
            continue;
        if (pr.second % 2 == 0)
            frq[1] += pr.second;
    }

    ans[1] = max(ans[0], frq[1]);

    int q;
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        w = min(w, 1ll);
        cout << ans[w] << nl;
    }
}

int main() {
#ifdef FILE_IO
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        run_case();
    }
}
/*
 * lcm(x,y) / gcd(x,y) = prod(i, (b_i)^(p_i)) (e.g. 2^3 * 3^6)
 * the result is a perfect square if all p_i is even
 * by the definition of lcm and gcd (hint: from a prime factors pov) we conclude that if two numbers x,y have the same parity of powers for their prime factors, then x,y are 'adjacent' by the definition of the problem
 * e.g.
 * let x = 20 = (2^2) * (5^1)
 * let y = 80 = (2^4) * (5^1)
 * x and y are adjacent because the parity of their factors match
 *
 * for set S of adjacent numbers [s1, s2, ..., sn] the simplest number X adjacent to this list is X = prod(i, (b_i) ^ (1)) if b_i was raised to an odd power among the factors in S
 * let S = [(2^2) * (5^1) * (3^8), (2^4) * (5^7)], then X = 5^1 (we exclude factors with an even power because they exist in X raised to power 0 which is even)
 */
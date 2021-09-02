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
const int MXN = 5e3 + 7;
int tcs;

int n,m;
string s,t;
int dp[MXN][MXN];
int vis[MXN][MXN];

int solve(int l, int r) {
    if(l == n || r == m){
        return 0;
    }
    if(vis[l][r] == tcs) {
        return dp[l][r];
    }

    vis[l][r] = tcs;
    int& ret = dp[l][r];

    ret = 0;

    if(s[l] == t[r]){
        ret = 1 + solve(l + 1, r + 1);
    }

    ret = max({ret, solve(l+1, r), solve(l, r + 1)});

    return ret;
}
void run_case() {
    cin >> n >> m >> s >> t;

    auto last = unique(all(s));
    s.erase(last, s.end());
    n = sof(s);

    last = unique(all(t));
    t.erase(last, t.end());
    m = sof(t);

    int lcs = solve(0, 0);

    cout << n + m - lcs << nl;
}

int main() {
#ifdef FILE_IO
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (tcs = 1; tcs <= T; tcs++)
        run_case();
}
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
const int MXN = 1e5 + 7;

ll ceil_div(ll x, ll y){
    return (x + (y - 1)) / y;
}

void run_case() {
    int n,x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    ll mn = 0, mx = 0;
    for(int i = 0; i < n; i++){
        mn += v[i];
        mx += ceil_div(v[i], x);
    }

    mn = ceil_div(mn, x);

    cout << mn << ' ' << mx << nl;
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
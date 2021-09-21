#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v) {
    for(const T &val: v)
        os << val << ' ';
    return os;
}

const int N = 2e5 + 7;
const int LOG = 18;
int a[N];
int mn[N][LOG];

int msb(int x){
    return 31 - __builtin_clz(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mn[i][0] = a[i];
    }

    for(int j = 1; j < LOG; j++)
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            mn[i][j] = min(mn[i][j-1], mn[i + (1 << (j - 1))][j-1]);

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int k = msb(r - l + 1);
        cout << min(mn[l][k], mn[r - (1 << k) + 1][k]) << nl;
    }
}
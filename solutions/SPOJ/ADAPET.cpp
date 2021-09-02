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
const int MXN = 2e5 + 7;
int tcs;
string s;

void run_case() {
    cin >> s;
    int k;
    cin >> k;

    int p = 0;
    vector<int> lps(sof(s), 0);
    for(int i = 1; i < sof(s); i++){
        if(s[i] == s[p]){
            p++;
            lps[i] = p;
        }
        else{
            if(p > 0) {
                p = lps[p-1];
                i--;
            }
            else{
                p = 0;
            }
        }
    }

    cout << s.size() * 1ll * k - (k-1ll) * lps.back() << nl;
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
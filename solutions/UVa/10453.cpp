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
const int MXN = 1e3+7;

string s;
int dp[MXN][MXN];
bool mid;
vector<int> ans;

int solve(int l, int r){
    if(l > r)
        return 0;

    int &ret = dp[l][r];
    if(~ret)
        return ret;

    if(s[l] == s[r])
        ret = solve(l + 1, r - 1);
    else
        ret = 1 + min(solve(l + 1, r), solve(l, r - 1));
    return ret;
}

void build(int l, int r){
    if(l > r)
        return;
    if(l == r)
        mid = true;

    if(s[l] == s[r]){
        ans.push_back(l);
        build(l + 1, r - 1);
    }
    else{
        if(solve(l,r) == 1 + solve(l + 1, r)){ /// BACK BONE
            ans.push_back(l);
            build(l+1, r);
        }
        else{
            ans.push_back(r);
            build(l, r - 1);
        }
    }
}
int main(){
#ifdef FILE_IO
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    while(cin >> s){
        memset(dp, -1, sizeof dp);
        mid = false;
        ans.clear();

        cout << solve(0, sof(s) - 1) << ' ';
        build(0, sof(s) - 1);

        for(int i = 0; i < sof(ans); i++) cout << s[ans[i]];
        for(int i = sof(ans) - 1 - mid; i >= 0; i--) cout << s[ans[i]];
        cout << nl;
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e4+1;

int dp[N][100];
int n,k;
int a[N];

int add(int x, int y){
    return ((x + y)%k + k) % k;
}
bool solve(int i, int sum){
    if(i == n){
        return (sum == 0);
    }
    int &ret = dp[i][sum];
    if(~ret)
        return ret;
    
    bool c1 = solve(i + 1, add(sum, a[i]));
    bool c2 = solve(i + 1, add(sum, -a[i]));
    
    return ret = (c1 | c2);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        for(int i = 0; i<n; i++) cin >> a[i];

        cout << (solve(0, 0) ? "Divisible" : "Not divisible") << '\n';
    }
}


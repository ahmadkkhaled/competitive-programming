#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;

int n;
int a[107];
int dp[107][50001];
int sum;

int solve(int idx, int cursum){
    if(idx == n){
        return abs(2*cursum - sum);
    }
    int &ret = dp[idx][abs(2*cursum - sum)];
    if(~ret) return ret;


   ret = min(solve(idx+1, cursum + a[idx]) , solve(idx+1, cursum));

   return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int t;
    cin >> t;
    while(t--){
        cin >> n;
        sum = 0;
        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
        }
        cout << solve(0, 0) << '\n';
    }
}


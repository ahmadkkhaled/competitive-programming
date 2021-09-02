#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e3+7;



int l,n;
int v[60];
int dp[51][51];

/**
 * lo and hi denote indices of v[]
 * no need to memoize lenlo, lenhi because each pair of lo,hi corresponds to a unique pair lenlo, lenhi
 */
int solve(int lo, int hi, int lenlo, int lenhi){
    if(hi <= lo){
        return 0;
    }
    int &ret = dp[lo][hi];
    if(~ret){
        return ret;
    }

    ret = INT_MAX;
    for(int i = lo; i<hi; i++){
        int COST  = lenhi - lenlo + 1;

        ret = min(ret, COST + solve(lo, i, lenlo, v[i]) + solve(i + 1, hi, v[i] + 1, lenhi) );
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    while(true){
        cin >> l;
        if(!l)
            break;

        cin >> n;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        cout << "The minimum cutting is " << solve(0, n, 1, l) << ".\n";
    }
}


#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;


class CasketOfStar{

public:
    int dp[51][51];
    vector<int> v;

    int solve(int l, int r){
        if(r-l == 2){
            return v[l] * v[r];
        }
        if(r - l == 1){
            return 0;
        }

        int &ret = dp[l][r];
        if(ret != -1)
            return ret;

        for(int i = l + 1; i < r; i++){
            ret = max(ret, solve(l, i) + solve(i, r) + v[l] * v[r]  );
        }
        return ret;
    }

    int maxEnergy(vector<int> weight){
        memset(dp, -1, sizeof(dp));
        int n = weight.size();
        v = weight;

        return solve(0, n - 1);
    }
};

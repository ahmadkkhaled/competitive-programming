/**
 * Building path using bottom-up approach
 */
#include <bits/stdc++.h>
using namespace std;

void there_are_fates_worse_than_death(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int di[] = {0, 0, 1, -1, -1, 2, -2, -2};
int dj[] = {1, -1, 0, 0, 0, -1, 1, -1 };

int main()
{
    there_are_fates_worse_than_death();
    bool first = true;
    while(true){
        int t,w;
        cin >> t >> w;
        if(cin.fail())
            break;
        if(first)
            first = false;
        else
            cout << endl;
        int n;
        cin >>  n;
        vector<pair<int,int>> vec;
        vec.push_back({0,0});
        for(int i=0; i<n; ++i){
            int d,v;
            cin >> d >> v;
            vec.push_back({3*w*d,v});
        }
        int dp[31][2000];
        for(int i=0; i<=t; ++i)
            dp[0][i] = 0;
        for(int i=1; i<=n; ++i){
            for (int j=0; j<=t; ++j){
                if(vec[i].first <= j)
                    dp[i][j] = max(dp[i-1][j], vec[i].second+dp[i-1][j-vec[i].first]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        stack<int> ans;
        int items = n;
        int time = t;
        for(int i=1; i<=items; ++i){
            if(dp[n][t] != dp[n-1][t]){
                ans.push(n);
                t = t - vec[n].first;
            }
            n=n-1;
        }
        cout << dp[items][time] << endl;
        cout << ans.size() << endl;
        while(!ans.empty()){
            int idx = ans.top();
            ans.pop();
            cout << vec[idx].first/(3*w) << " " << vec[idx].second << endl;
        }
    }
}

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, bool have, vector<int> &prices){
        if(idx == prices.size())
            return 0;

        int &ret = dp[idx][have];
        if(~ret)
            return ret;

        if(have){
            ret = solve(idx + 1, false, prices) + prices[idx];
        }else{
            ret = solve(idx + 1, true, prices) - prices[idx];
        }
        ret = max({0, ret, solve(idx + 1, have, prices)});
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        dp.resize(prices.size(), vector<int>(2, -1));
        return solve(0, false, prices);
    }
};
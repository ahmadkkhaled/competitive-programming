#include <bits/stdc++.h>
using namespace std;

int movei[] = {0, 0, 1, -1, 1, 1, -1, -1};
int movej[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e5+1;


class MessageMess{
    public:
        long long dp[60][60];
        string s;
        vector<string> v;
        bool exists(string targ){
            for(string &str : v) if(targ == str) return true;
            return false;
        }

        long long solve(int l, int r){
            long long &ret = dp[l][r];
            if(~ret) return ret;

            if(r == s.size() - 1){
                if(exists(s.substr(l , r-l+1))) return ret = 1LL;
                return ret = 0; /// l != 0 && substring does not exist in dictionary
            }

            ret = 0;
            if(exists(s.substr(l, r - l + 1))) ret = solve(r+1, r+1);
            ret += solve(l, r+1);

            return ret;

        }
        string build(int l, int r){
            if(r == s.size() - 1){
                return s.substr(l, r - l + 1);
            }
            if(dp[r+1][r+1] == 1){
                return s.substr(l, r - l + 1) + ' ' + build(r+1, r+1);
            }
            else{
                return build(l, r+1);
            }
        }
        string restore(vector<string> &dic, string &message){
            memset(dp, -1, sizeof(dp));
            s = message;
            v = dic;
            solve(0,0);
            if(dp[0][0] == 0) return "IMPOSSIBLE!";
            if(dp[0][0] > 1) return "AMBIGUOUS!";
            return build(0,0);
        }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(string &s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> ans(mp.size());
        int i = 0;
        for(auto &p : mp){
            ans[i++] = p.second;
        }
        
        return ans;
    }
};
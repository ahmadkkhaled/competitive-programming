class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left = 0;
        for(int i = 0; i < shift.size(); i++){
            if(shift[i][0] == 0)
                left += shift[i][1];
            else
                left -= shift[i][1];
        }
        left %= (int)s.size();
        rotate(s.begin(), s.begin() + left + s.size() * (left < 0), s.end());
        return s;
    }
};
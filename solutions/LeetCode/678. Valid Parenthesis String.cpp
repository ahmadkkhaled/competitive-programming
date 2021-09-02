class Solution {
public:
    bool check(int &flag, int &stars){
        if(flag < 0){
            if(stars){
                stars--;
                flag++;
                return true;
            }
            return false;
        }
        return true;
    }
    bool checkValidString(string s) {
        int flag = 0, stars = 0;
        const int n = s.size();
        
        bool can = true;
        for(int i=0; i<n; i++){
            if(s[i] == '(') flag++;
            else if(s[i] == ')') flag--;
            else stars++;
            can &= check(flag, stars);
        }
        
        flag = 0, stars = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == ')') flag++;
            else if(s[i] == '(') flag--;
            else stars++;
            can &= check(flag, stars);
        }
        return can;
    }
};
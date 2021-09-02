class Solution {
public:
    int removeChars(string &s){
        int l = 0;
        for(char c : s){
            if(c == '#'){
                if(l > 0) l--;
            }
            else{
                s[l] = c;
                l++;
            }
        }
        return l;
    }
    bool backspaceCompare(string S, string T) {
        int _t, _s;
        _t = removeChars(S);
        _s = removeChars(T);
        
        if(_s != _t){
            return false;
        }
        for(int i = 0; i < _s; i++){
            if(S[i] != T[i])
                return false;
        }
        return true;
    }
};
class Solution {
public:
    int trailingZeroes(int n) {
        int fv = 0;
        while(n){
            n/=5;
            fv+=n;
        }
        return fv;
    }
};
/*
	Solving the problem in O(n) with constant space
	Using the input and output vectors as prefix and suffix arrays.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        vector<int> out(n); // suffix
        for(int i = n - 1; i>=0; i--)
            out[i] = nums[i] * (i == n-1? 1 : out[i+1]);

        for(int i = 1; i < n; i++)
            nums[i] *= nums[i-1];

        for(int i = 0; i<n; i++){
            int prx = (i == 0 ? 1 : nums[i-1]);
            int suf = (i == n-1 ? 1 : out[i+1]);
            out[i] = suf * prx;
        }

        return out;
    }
};
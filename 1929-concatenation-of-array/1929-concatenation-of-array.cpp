class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = nums;
        ans.insert(ans.end(), nums.begin(), nums.end());
        // for (int i = 0; i < n; i++) {
        //     ans[i] = nums[i];       
        //     ans[i + n] = nums[i];   
        // }
        return ans;
    }
};
class Solution {
private:
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prev + 1] != -1) return dp[ind][prev+1];

        //Not Take
        int len = 0 + f(ind+1, prev, nums, dp);
        if(prev == -1 || nums[ind] > nums[prev]){
            //Take
            len = max(len, 1 + f(ind+1, ind, nums, dp));
        }

        return dp[ind][prev+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        return f(0, -1, nums, dp);
    }
};

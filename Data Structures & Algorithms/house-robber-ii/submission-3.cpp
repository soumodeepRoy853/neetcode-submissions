class Solution {
private:
    int f(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + f(idx-2, nums, dp);
        int notTake = f(idx-1, nums, dp);

        return dp[idx] = max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int>firstHouse(nums.begin(), nums.end()-1);
        vector<int>secondHouse(nums.begin()+1, nums.end());

        vector<int> dp(n+1, -1);
        vector<int> dp2(n+1, -1);

        return max(
            f(firstHouse.size()-1, firstHouse, dp),
            f(secondHouse.size()-1, secondHouse, dp2)
        );
    }
};

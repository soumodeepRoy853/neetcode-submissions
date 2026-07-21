class Solution {
private:
    bool f(int ind, int targetSum, vector<int>& nums, vector<vector<int>>& dp){
        if(targetSum == 0) return true;
        if(ind == nums.size()) return false;

        if(dp[ind][targetSum] != -1) return dp[ind][targetSum];
        //take
        bool take = false;
        // not take
        bool notTake = f(ind+1, targetSum, nums, dp);

        if(nums[ind] <= targetSum){
            take = f(ind+1, targetSum - nums[ind], nums, dp);
        }

        return dp[ind][targetSum] = take || notTake;

    }
public:
    bool canPartition(vector<int>& nums) {
        // ToatalSum = Sum of all arr elem;
        // TargetSum = TotalSum/2;
        int totalSum = 0;
        for(auto num : nums){
            totalSum += num;
        }
        if(totalSum % 2 != 0) return false;
        int targetSum = totalSum/2;

        int n = nums.size();

        vector<vector<int>>dp (n, vector<int> (targetSum+1, -1));

        return f(0, targetSum, nums, dp);
    }
};

class Solution {
private:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int idn = i; idn<=j; idn++){
            int cost = nums[i-1] * nums[idn] * nums[j+1] + f(i, idn-1, nums, dp) + f(idn+1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;

    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        return f(1, n, nums, dp);
    }
};

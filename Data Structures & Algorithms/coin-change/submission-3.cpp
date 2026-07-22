class Solution {
private:
int f(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
    if(idx == 0){
        if(amount % coins[0] == 0)return amount / coins[0];
        else return 1e9;
    }

    if(dp[idx][amount] != -1) return dp[idx][amount];

    int take = INT_MAX;
    int notTake = 0 + f(idx-1, coins, amount, dp);

    if(coins[idx] <= amount){
        take = 1 + f(idx, coins, amount - coins[idx], dp);
    }

    return dp[idx][amount] = min(take, notTake);
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

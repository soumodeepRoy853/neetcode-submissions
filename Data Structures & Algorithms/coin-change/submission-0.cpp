class Solution {
private:
int f(int idx, vector<int>& coins, int amount){
    if(idx == 0){
        if(amount % coins[0] == 0)return amount / coins[0];
        else return 1e9;
    }

    int take = INT_MAX;
    int notTake = 0 + f(idx-1, coins, amount);

    if(coins[idx] <= amount){
        take = 1 + f(idx, coins, amount - coins[idx]);
    }

    return min(take, notTake);
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n-1, coins, amount);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

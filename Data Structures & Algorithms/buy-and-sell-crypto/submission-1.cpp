class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit = prices[0], maxProfit = 0;

        for(int i=1; i<prices.size(); i++){
            minProfit = min(minProfit, prices[i]);
            int profit = prices[i] - minProfit;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};

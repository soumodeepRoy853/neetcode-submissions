class Solution {
private:
    int f(int i, int j, vector<int>& nums){
        if(i > j) return 0;

        int maxi = INT_MIN;
        for(int idn = i; idn<=j; idn++){
            int cost = nums[i-1] * nums[idn] * nums[j+1] + f(i, idn-1, nums) + f(idn+1, j, nums);
            maxi = max(maxi, cost);
        }
        return maxi;

    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        return f(1, n, nums);
    }
};

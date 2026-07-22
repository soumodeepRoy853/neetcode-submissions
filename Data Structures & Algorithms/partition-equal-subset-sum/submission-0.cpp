class Solution {
private:
    bool f(int ind, int targetSum, vector<int>& nums){
        if(targetSum == 0) return true;
        if(ind == nums.size()) return false;
        //take
        bool take = false;
        // not take
        bool notTake = 1 + f(ind+1, targetSum, nums);

        if(nums[ind] <= targetSum){
            take = f(ind+1, targetSum - nums[ind], nums);
        }

        return take || notTake;

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

        return f(0, targetSum, nums);
    }
};

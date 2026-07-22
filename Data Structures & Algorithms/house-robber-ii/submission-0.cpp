class Solution {
private:
    int f(int idx, vector<int>& nums){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        int take = nums[idx] + f(idx-2, nums);
        int notTake = f(idx-1, nums);

        return max(take, notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>firstHouse(nums.begin(), nums.end()-1);
        vector<int>secondHouse(nums.begin()+1, nums.end());

        return max(
            f(firstHouse.size()-1, firstHouse),
            f(secondHouse.size()-1, secondHouse)
        );
    }
};

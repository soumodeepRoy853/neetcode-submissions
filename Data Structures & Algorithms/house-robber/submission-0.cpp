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

        return f(n-1, nums);
    }
};

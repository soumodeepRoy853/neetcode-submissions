class Solution {
private:
    int f(int ind, int prev, vector<int>& nums){
        if(ind == nums.size()) return 0;

        //Not Take
        int len = 0 + f(ind+1, prev, nums);
        if(prev == -1 || nums[ind] > nums[prev]){
            //Take
            len = max(len, 1 + f(ind+1, ind, nums));
        }

        return len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return f(0, -1, nums);
    }
};

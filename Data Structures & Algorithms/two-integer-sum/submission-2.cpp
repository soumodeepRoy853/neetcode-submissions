class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());

        int s = 0, e = nums.size()-1;

        for(int i=0; i<nums.size(); i++){
            if(nums[s] + nums[e] == target){
                return {s, e};
            } else if(nums[s] + nums[e] < target){
                s++;
            } else{
                e--;
            }
        }
        return {};
    }
};

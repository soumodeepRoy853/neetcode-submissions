class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int left = 0, right = n-1, maxWater = 0;

        while(left <= right){
            int currArea = min(heights[left], heights[right]) * (right - left);
            maxWater = max(maxWater, currArea);

            if(heights[left] < heights[right]){
                left ++;
            } else{
                right--;
            }
        }
        return maxWater;
    }
};

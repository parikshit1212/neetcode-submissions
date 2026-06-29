class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (sum < 0) {
                // no point in carrying it forward 
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

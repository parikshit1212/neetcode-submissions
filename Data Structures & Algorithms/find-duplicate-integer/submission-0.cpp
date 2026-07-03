class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            int value = abs(nums[i]);
            if(nums[value] < 0) {
                ans = value;
                break;
            } else {
                nums[value] = -1 * nums[value];
            }
        }
        return ans;
    }
};

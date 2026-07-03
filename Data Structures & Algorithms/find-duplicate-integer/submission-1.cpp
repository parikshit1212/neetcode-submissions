class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int value = abs(nums[i]);
            if(nums[value] < 0) {
                return value;
            } else {
                nums[value] = -1 * nums[value];
            }
        }
    }
};

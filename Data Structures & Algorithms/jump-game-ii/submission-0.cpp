class Solution {
public:
    int jump(vector<int>& nums) {
        int lastEnd = 0;
        int maxReachableIndex = 0;
        int jumps = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            maxReachableIndex = max(maxReachableIndex, nums[i] + i);
            if (i == lastEnd) {
                jumps += 1;
                lastEnd = maxReachableIndex;
            }
        }
        return jumps;
    }
};

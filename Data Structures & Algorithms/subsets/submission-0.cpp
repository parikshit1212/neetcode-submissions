class Solution {
private:
    void findSubsets(vector<int> &nums, int index, vector<int> subset, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }
        // We have 2 choices - either pick or not pick
        findSubsets(nums, index+1, subset, ans);
        subset.push_back(nums[index]);
        findSubsets(nums, index+1, subset, ans);
        subset.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        findSubsets(nums, 0, subset, ans);
        return ans;
    }
};

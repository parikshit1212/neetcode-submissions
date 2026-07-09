class Solution {
private: 
    void computeSubsets(vector<int> &nums, int index, vector<int> &res, vector<vector<int>> &ans) {
        ans.push_back(res);
        for(int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1]) continue;
            res.push_back(nums[i]);
            computeSubsets(nums, i+1, res, ans);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        computeSubsets(nums, 0, res, ans);
        return ans;
    }
};
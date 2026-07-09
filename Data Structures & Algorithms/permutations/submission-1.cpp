class Solution {
private:
    void calculatePermutations(vector<int>& nums, vector<int> &res, 
    vector<vector<int>> &ans, int index) {
        if (index == nums.size()) {
            ans.push_back(res);
            return;
        }

        // Now at this position we have option to pick any of the element except already picked one
        for(int i = index; i < nums.size(); i++) {
            // otherwise we can pick this in res
            res.push_back(nums[i]);
            swap(nums[i], nums[index]);
            calculatePermutations(nums, res, ans, index+1);
            // backtrack for new solutions
            res.pop_back();
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> ans;
        calculatePermutations(nums, res, ans, 0);
        return ans;
    }
};

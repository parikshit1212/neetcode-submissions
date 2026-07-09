class Solution {
private:
    void calculatePermutations(vector<int>& nums, vector<int> &res, vector<vector<int>> &ans, unordered_map<int,bool> &mp) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        // Now at this position we have option to pick any of the element except already picked one
        for(int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]]) continue;
            // otherwise we can pick this in res
            res.push_back(nums[i]);
            mp[nums[i]] = true;
            calculatePermutations(nums, res, ans, mp);
            // backtrack for new solutions
            res.pop_back();
            mp.erase(nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> ans;
        unordered_map<int, bool> mp;
        calculatePermutations(nums, res, ans, mp);
        return ans;
    }
};

class Solution {
private: 
    void findCombination(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &res) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }
        // We can pick an element from current position and have option to pick it again 
        res.push_back(candidates[index]);
        findCombination(candidates, target-candidates[index], index, ans, res);
        // or do not pick
        res.pop_back();
        findCombination(candidates, target, index+1, ans, res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        findCombination(candidates, target, 0, ans, res);
        return ans;
    }
};
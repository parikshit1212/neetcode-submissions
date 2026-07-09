class Solution {
private:
    void findCombinations(vector<int> &candidates, int target, int index, vector<int> &res, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (target < 0 || index >= candidates.size()) return;
        int prev = candidates[index];
        for(int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == prev) continue;
            prev = candidates[i];
            res.push_back(candidates[i]);
            findCombinations(candidates, target-candidates[i], i+1, res, ans);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> ans;
        findCombinations(candidates, target, 0, combination, ans);
        return ans;
    }
};
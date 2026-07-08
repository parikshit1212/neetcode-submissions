class Solution {
private:
    void findCombinations(string digits, int index, vector<string> &ans, string str, vector<string> &combos) {
        if (index == digits.size()) {
            ans.push_back(str);
            return;
        }
        // for the current index we have all the posible characters in the combos vector
        int idx = digits[index] - '0';
        for(int i = 0; i < combos[idx].size(); i++) {
            // can pick all of them one by one
            findCombinations(digits, index+1, ans, str + combos[idx][i], combos);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> combos = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string str = "";
        findCombinations(digits, 0, ans, str, combos);
        return ans;
    }
};

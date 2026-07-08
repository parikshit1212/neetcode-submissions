class Solution {
private:
    void generateValidParanthesis(vector<string> &ans, string str, int leftCount, int rightCount) {
        if(leftCount == 0 && rightCount == 0) {
            ans.push_back(str);
            return;
        }

        if (leftCount > 0) {
            generateValidParanthesis(ans, str + '(', leftCount-1, rightCount);
        }
        if (rightCount > 0 && rightCount > leftCount) {
            generateValidParanthesis(ans, str + ')', leftCount, rightCount-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        generateValidParanthesis(ans, str, n, n);
        return ans;
    }
};

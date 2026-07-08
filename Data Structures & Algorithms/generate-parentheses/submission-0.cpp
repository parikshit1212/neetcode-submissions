class Solution {
private: 

    void generateCorrectParanthesis(vector<string> &ans, string str, int n, int sum) {
        if (sum < 0) return;
        if (str.size() == 2*n && sum == 0) {
            ans.push_back(str);
            return;
        }
        if (str.size() == 2*n) return;

        // now we can pick any paranthesis
        generateCorrectParanthesis(ans, str + '(', n, sum+1);
        generateCorrectParanthesis(ans, str + ')', n, sum-1);
    }

public:
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
      string str = "";
      int sum = 0;
      generateCorrectParanthesis(ans, str, n, sum);
      return ans;  
    }
};
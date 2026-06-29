class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                // if left exists the use that, if star exists then use it as left one
                if (left.empty() && star.empty()) return false;
                if (!left.empty()) {
                    left.pop();
                } else {
                    star.pop();
                }
            }
        }

        // now check if only left '(' exists then it should also be balanced by '*'
        while(!left.empty() && !star.empty()) {
            // if there is left '(' then in string '*' should come on the right side
            if (left.top()  > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};

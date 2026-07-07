class Solution {
private: 
    vector<int> prevSmallerElement(vector<int> &heights) {
        vector<int> ans(heights.size());
        stack<int> st;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int> &heights) {
        vector<int> ans(heights.size());
        stack<int> st;
        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? heights.size() : st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevSE = prevSmallerElement(heights);
        vector<int> nextSE = nextSmallerElement(heights);
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            int area = (nextSE[i] - prevSE[i] - 1) * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};

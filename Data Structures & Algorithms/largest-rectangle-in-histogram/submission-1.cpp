class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int index = st.top();
                st.pop();
                int nextSmaller = i;
                int prevSmaller = st.empty() ? -1 : st.top();
                ans = max(ans, (nextSmaller - prevSmaller - 1) * heights[index]);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int index = st.top();
            st.pop();
            int prevSmaller = st.empty() ? -1 : st.top();
            int nextSmaller = heights.size();
            ans = max(ans, (nextSmaller - prevSmaller - 1) * heights[index]);
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> PSE(n); //saving prev smaller 
        vector<int> NSE(n); //saving next smaller



        // Compute PSE
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Reset stack for NSE
        st = stack<int>();

        // Compute NSE
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Compute maximum area
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int area = heights[i] * (NSE[i] - PSE[i] - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
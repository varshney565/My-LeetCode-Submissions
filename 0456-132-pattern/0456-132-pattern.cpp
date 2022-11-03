class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> pre(n,INT_MAX);
        for(int i = 0 ; i < n ; i++){
            pre[i] = nums[i];
            if(i) pre[i] = min(pre[i],pre[i-1]);
        }
        st.push(nums[n-1]);
        for(int i = n - 2 ; i > 0 ; i--){
            int s2 = nums[i],s1 = pre[i-1];
            if(s1 >= s2) continue;
            while(!st.empty() && st.top() <= s1) st.pop();
            if(!st.empty() && s2 > st.top())
                return true;
            st.push(nums[i]);
        }
        return false;
    }
};
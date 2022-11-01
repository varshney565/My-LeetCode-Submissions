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
            int s2 = nums[i];
            int s3 = INT_MAX;
            int s1 = pre[i-1];
            while(!st.empty() && st.top() < s2){
                s3 = st.top();
                st.pop();
            }
            if(s1 < s2 && s2 > s3 && s1 < s3)
                return true;
            st.push(nums[i]);
        }
        return false;
    }
};
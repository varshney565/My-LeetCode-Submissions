class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        function<int(int)> go = [&](int ei){
            if(dp[ei] != -1)
                return dp[ei];
            int ans = 1;
            for(int i = ei-1 ; i >= 0 ; i--){
                if(nums[ei] > nums[i]){
                    ans = max(ans,1+go(i));
                }
            }
            return dp[ei] = ans;
        };
        int ans = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            ans = max(ans,go(i));
        }
        return ans;
    }
};
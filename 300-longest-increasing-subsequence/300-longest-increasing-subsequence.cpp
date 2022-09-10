class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        function<int(int,int)> go = [&](int ind,int prev){
            if(ind == n)
                return dp[ind][prev] = 0;
            
            if(dp[ind][prev] != -1) return dp[ind][prev];
            
            if(prev == n+1 || nums[prev] < nums[ind]){
                return dp[ind][prev] = max(go(ind+1,prev),1+go(ind+1,ind));
            }else{
                return dp[ind][prev] = go(ind+1,prev);
            }
        };
        return go(0,n+1);
    }
};
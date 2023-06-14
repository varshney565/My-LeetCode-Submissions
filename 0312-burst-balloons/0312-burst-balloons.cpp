class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        function<int(int,int)> go = [&](int st,int en){
            if(st > en) return 0;
            if(dp[st][en] != -1) return dp[st][en];
            int lf = 1,rf = 1;
            if(st-1 >= 0) lf = nums[st-1];
            if(en+1 < n) rf = nums[en+1];
            int ans = 0;
            for(int last = st ; last <= en ; last++){
               ans = max(ans,nums[last]*lf*rf+go(st,last-1)+go(last+1,en));
            }
            return dp[st][en] = ans;
        };
        return go(0,n-1);
    }
};
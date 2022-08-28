class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,-1);
        function<int(int)> dfs = [&](int n){
            if(n < 0) return 0;
            if(dp[n] != -1) return dp[n];
            int ans = cost[n];
            ans += min(dfs(n-1),dfs(n-2));
            return dp[n] = ans;
        };
        int ans = dfs(n);
        return ans;
    }
};
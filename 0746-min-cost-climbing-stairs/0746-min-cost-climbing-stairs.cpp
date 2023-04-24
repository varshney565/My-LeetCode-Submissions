class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size()+1,-1);
        function<int(int)> go = [&](int n){
            if(n <= 1) return dp[n] = cost[n];
            if(dp[n] != -1) return dp[n];
            return dp[n] = (n < cost.size() ? cost[n] : 0) + min(go(n-1),go(n-2));
        };
        return go(n);
    }
};
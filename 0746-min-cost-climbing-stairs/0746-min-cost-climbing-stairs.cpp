class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size()+1,-1);
        for(int n = 0 ; n <= cost.size() ; n++){
            if(n <= 1) {
                dp[n] = cost[n];
                continue;
            }
            dp[n] = (n < cost.size() ? cost[n] : 0) + min(dp[n-1],dp[n-2]);
        }
        return dp[cost.size()];
    }
};
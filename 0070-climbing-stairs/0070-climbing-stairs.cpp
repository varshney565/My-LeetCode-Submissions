class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        function<int(int)> go = [&](int n){
            if(n <= 1) return dp[n] = 1;
            if(dp[n] != -1) return dp[n];
            return dp[n] = go(n-1)+go(n-2);
        };
        return go(n);
    }
};
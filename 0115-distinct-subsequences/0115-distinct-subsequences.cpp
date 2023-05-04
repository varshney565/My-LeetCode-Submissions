class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(m == 0) return dp[n][m] = 1;
            if(n == 0) return dp[n][m] = 0;
            if(dp[n][m] != -1) return dp[n][m];
            int ans = 0;
            if(s[n-1] == t[m-1]){
                ans = go(n-1,m-1);
            }
            ans += go(n-1,m);
            return dp[n][m] = ans;
        };
        return go(n,m);
    }
};
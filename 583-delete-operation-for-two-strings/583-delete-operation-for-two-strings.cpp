class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(n == 0 && m == 0)
                return 0;
            if(n == 0 || m == 0)
                return n?n:m;
            if(dp[n][m] != -1) return dp[n][m];
            int ans = (s[n-1]==t[m-1]?go(n-1,m-1):1+min(go(n-1,m),go(n,m-1)));
            return dp[n][m] = ans;
        };
        return go(n,m);
    }
};
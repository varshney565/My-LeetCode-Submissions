class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int N,int M){
            for(int n = 0 ; n <= N ; n++){
                for(int m = 0 ; m <= M ; m++){
                    if(n == 0 && m == 0){
                        dp[n][m] = 0;
                        continue;
                    }
                    if(n == 0 || m == 0){
                        dp[n][m] = n?n:m;
                        continue;
                    }
                    int ans = (s[n-1]==t[m-1]?dp[n-1][m-1]:1+min(dp[n-1][m],dp[n][m-1]));
                    dp[n][m] = ans;
                }
            }
            return dp[N][M];
        };
        return go(n,m);
    }
};
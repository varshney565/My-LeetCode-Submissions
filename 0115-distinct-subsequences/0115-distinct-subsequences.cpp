class Solution {
public:
    int numDistinct(string s, string t) {
        int N = s.size();
        int M = t.size();
        vector<vector<double>> dp(N+1,vector<double>(M+1,0));
        for(int n = 0 ; n <= N ; n++){
            for(int m = 0 ; m <= M ; m++){
                if(m == 0) {
                    dp[n][m] = 1;
                    continue;
                }
                if(n == 0) {
                    dp[n][m] = 0;
                    continue;
                }
                if(n < m){
                    dp[n][m] = 0;
                    continue;
                }
                if(s[n-1] == t[m-1]){
                    dp[n][m] = dp[n-1][m-1];
                }
                dp[n][m] += dp[n-1][m];
            }
        }
        return dp[N][M];
    }
};
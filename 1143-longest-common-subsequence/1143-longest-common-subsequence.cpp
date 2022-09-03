class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int N,int M){
            for(int n = 0 ; n <= N ; n++){
                for(int m = 0 ; m <= M ; m++){       
                    if(n == 0 || m == 0){
                        dp[n][m] = 0;
                        continue;
                    }
                    if(text1[n-1] == text2[m-1]){
                        dp[n][m] = 1+dp[n-1][m-1];
                    }else{
                        dp[n][m] = max(dp[n-1][m],dp[n][m-1]);
                    }
                }
            }
            return dp[N][M];
        };
        return go(n,m);
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(n == 0 || m == 0) return dp[n][m] = 0;
            if(dp[n][m] != -1) return dp[n][m];
            if(word1[n-1] == word2[m-1])
                return dp[n][m] = 1+go(n-1,m-1);
            return dp[n][m] = max(go(n-1,m),go(n,m-1));
        };
        int lcs = go(n,m);
        return n+m-2*lcs;
    }
};
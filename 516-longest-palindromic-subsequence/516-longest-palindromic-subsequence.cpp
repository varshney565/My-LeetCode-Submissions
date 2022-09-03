class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        function<int(int,int)> go = [&](int i,int j){
            if(i > j)
                return 0;
            if(i == j)
                return 1;
            if(dp[i][j] != -1)
                return dp[i][j];
            if(s[i] == s[j]){
                return dp[i][j] = 2+go(i+1,j-1);
            }else{
                return dp[i][j] = max(go(i+1,j),go(i,j-1));
            }
        };
        return go(0,n-1);
    }
};
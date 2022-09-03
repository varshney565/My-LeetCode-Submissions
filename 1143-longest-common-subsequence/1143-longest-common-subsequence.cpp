class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int i1,int i2){
            if(i1 == n || i2 == m){
                return dp[i1][i2] = 0;
            }
            if(dp[i1][i2] != -1) return dp[i1][i2];
            if(text1[i1] == text2[i2]){
                return dp[i1][i2] = 1+go(i1+1,i2+1);
            }else{
                return dp[i1][i2] = max(go(i1+1,i2),go(i1,i2+1));
            }
        };
        return go(0,0);
    }
};
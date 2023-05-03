class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int gap = 1 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 1){
                    dp[i][j] = 1;
                }else if(gap == 2){
                    dp[i][j] = s[i]==s[j]?2:1;
                }else{
                    dp[i][j] = ( s[i]==s[j] ? 2+dp[i+1][j-1] : max(dp[i][j-1],dp[i+1][j]) );
                }
                j++;
                i++;
            }
        }
        return dp[0][n-1];
    }
};
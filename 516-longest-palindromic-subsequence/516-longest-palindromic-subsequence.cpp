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
            int SmallAns1 = go(i+1,j);
            int SmallAns2 = go(i,j-1);
            int SmallAns3 = go(i+1,j-1)+((s[i] == s[j])?2:0);
            return dp[i][j] = max(max(SmallAns1,SmallAns2),SmallAns3);
        };
        return go(0,n-1);
    }
};
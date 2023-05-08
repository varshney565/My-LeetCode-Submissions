class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(m == 0 && n == 0) return dp[n][m] = 1;
            if(n == 0){
                for(int i = m - 1 ; i >= 0 ; i-=2){
                    if(p[i] != '*') return dp[n][m] = 0;
                }
                return dp[n][m] = 1;
            }
            if(m == 0) return dp[n][m] = 0;
            if(dp[n][m] != -1) return dp[n][m];
            bool ans = false;
            if(p[m-1] == '.' || s[n-1] == p[m-1]){
                ans = ans || go(n-1,m-1);
            }else if(p[m-1] == '*'){
                char prevCh = p[m-2];
                bool op1 = go(n,m-2); //zero occurence of the last character
                bool op2 = false;
                if(prevCh == '.' || prevCh == s[n-1]){
                    op2 = go(n-1,m);
                }
                ans = ans || op1 || op2;
            }
            return dp[n][m] = ans ? 1 : 0;
        };
        return go(n,m);
    }
};
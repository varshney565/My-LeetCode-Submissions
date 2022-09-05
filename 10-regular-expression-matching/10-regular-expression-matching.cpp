class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(dp[n][m] != -1) return dp[n][m];
            if(n == 0 && m == 0) return dp[n][m] = 1;
            if(m == 0) return dp[n][m] = 0;
            if(n == 0){
                int i = m-1;
                while(i >= 0){
                    if(p[i] != '*')
                        return dp[n][m] = 0;
                    i -= 2;
                }
                return dp[n][m] = 1;
            }
            if(s[n-1] == p[m-1]) return dp[n][m] = go(n-1,m-1);
            else if(p[m-1] == '.') return dp[n][m] = go(n-1,m-1);
            else if(p[m-1] == '*'){
                int res = 0;
                res = res || go(n,m-2);
                res = res || go(n,m-1);
                res = res || ((p[m-2] == s[n-1] || p[m-2] == '.') && go(n-1,m-1));
                res = res || ((p[m-2] == s[n-1] || p[m-2] == '.') && go(n-1,m));
                return dp[n][m] = res;
            }else{
                return dp[n][m] = 0;
            }
        };
        
        function<int(int,int)> go_dp = [&](int N,int M){
            for(int n = 0 ; n <= N ; n++){
                for(int m = 0 ; m <= M ; m++){
                    if(n == 0 && m == 0) {
                        dp[n][m] = 1;continue;
                    }
                    if(m == 0){
                        dp[n][m] = 0;continue;
                    }
                    if(n == 0){
                        int i = m-1;
                        int ans = 1;
                        while(i >= 0){
                            if(p[i] != '*'){
                                ans = 0;
                                break;
                            }
                            i -= 2;
                        }
                        dp[n][m] = ans;
                        continue;
                    }
                    
                    if(s[n-1] == p[m-1]) dp[n][m] = dp[n-1][m-1];
                    else if(p[m-1] == '.') dp[n][m] = dp[n-1][m-1];
                    else if(p[m-1] == '*'){
                        int res = 0;
                        res = res || dp[n][m-2];
                        res = res || dp[n][m-1];
                        res = res || ((p[m-2] == s[n-1] || p[m-2] == '.') && dp[n-1][m-1]);
                        res = res || ((p[m-2] == s[n-1] || p[m-2] == '.') && dp[n-1][m]);
                        dp[n][m] = res;
                    }else{
                        dp[n][m] = 0;
                    }
                }
            }
            return dp[N][M];
        };
        
        return go_dp(n,m);
    }
};
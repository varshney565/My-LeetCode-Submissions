class Solution {
public:
    const int mod = 1e9+7;
    int numWays(vector<string>& words, string target) {
        int n1 = target.size();
        int n2 = words[0].size();
        int m = words.size();
        vector<vector<int>> cnt(n2,vector<int>(26,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n2 ; j++){
                cnt[j][words[i][j]-'a']++;
            }
        }
        
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(m < n) return 0;
            if(n < 0) return 1;
            if(dp[n][m] != -1) return dp[n][m];
            //option1 :: take that char count.
            int ans = 0;
            int val = cnt[m][target[n]-'a'];
            if(val) ans = (ans + ((long long)val*go(n-1,m-1))%mod)%mod;
            //option2 :: don't take that char count.
            ans = (ans + go(n,m-1))%mod;
            return dp[n][m] = ans;
        };
        return go(n1-1,n2-1);
    }
};
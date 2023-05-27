class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cnt(n,vector<int>(n,0));
        for(int gap = 2 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 2){
                    cnt[i][j] = ((s[i] == s[j]) ? 0 : 1);
                }else{
                    cnt[i][j] = ((s[i] == s[j]) ? 0 : 1) + cnt[i+1][j-1];
                }
                i++;
                j++;
            }
        }
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        function<int(int,int)> go = [&](int n,int k){
            if(k == 1){
                return dp[n][k] = cnt[0][n-1];
            }
            if(n == k){
                return dp[n][k] = 0;
            }
            if(dp[n][k] != -1) return dp[n][k];
            int ans = 100;
            for(int i = n - 1 ; i >= max(0,k - 1); i--){
                ans = min(ans,go(i,k-1)+cnt[i][n-1]);
            }
            return dp[n][k] = ans;
        };
        return go(n,k);
    }
};
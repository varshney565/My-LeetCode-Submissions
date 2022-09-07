class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        //making dp for palindrom number
        for(int gap = 1 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 1){
                    dp[i][j] = 1;
                }else if(gap == 2){
                    dp[i][j] = (s[i] == s[j])?1:0;
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1])?1:0;
                }
                i++;
                j++;
            }
        }
        //dp is ready ...
        
        //FinalDpForAnswer ...
        vector<int> dp2(n+1,-1);
        function<int(int)> go = [&](int n){
            if(dp2[n] != -1) return dp2[n];
            if(dp[0][n-1])
                return dp2[n] = 0;
            
            int ans = INT_MAX;
            for(int st = n-1 ; st > 0 ; st--){
                if(dp[st][n-1]){
                    ans = min(ans,go(st)+1);
                }
            }
            return dp2[n] = ans;
        };
        return go(n);
    }
};
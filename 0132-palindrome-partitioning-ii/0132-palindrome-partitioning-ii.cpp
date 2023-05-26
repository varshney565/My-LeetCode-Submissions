class Solution {
public:
    int minCut(string str) {
        //part 1 : prepare lp_substring dp
        int n = str.size();
        vector<vector<bool>> isPali(n,vector<bool>(n,false));
        for(int gap = 1 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 1){
                    isPali[i][j] = true;
                }else if(gap == 2){
                    isPali[i][j] = (str[i] == str[j]);
                }else{
                    isPali[i][j] = (str[i] == str[j] && isPali[i+1][j-1]);
                }
                i++;
                j++;
            }
        }
        //part 2 : now find the optimal way to cut the string in minimal parts.
        vector<int> dp(n+1,-1);
        function<int(int)> go = [&](int n){
            if(isPali[0][n-1]) return dp[n] = 0;
            if(dp[n] != -1) return dp[n];
            int ans = INT_MAX;
            for(int i = n - 1 ; i >= 0 ; i--){
                if(isPali[i][n-1]){
                    ans = min(ans,1+go(i));
                }
            }
            return dp[n] = ans;
        };
        return go(n);
    }
};
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ans = 0;
        for(int gap = 1 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 1){
                    dp[i][j] = true,ans++;
                }else if(gap == 2){
                    dp[i][j] = (s[i] == s[j]?true,ans++:false);
                }else{
                    dp[i][j] = ((s[i] == s[j] && dp[i+1][j-1])?true,ans++:false);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
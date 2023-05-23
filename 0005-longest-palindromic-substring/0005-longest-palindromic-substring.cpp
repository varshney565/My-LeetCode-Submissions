class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int st = 0;
        int en = 0;
        for(int gap = 1 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 1)
                    dp[i][j] = true;
                else if(gap == 2){
                    if(s[i] == s[j]) dp[i][j] = true;
                }else{
                    dp[i][j] = ((s[i] == s[j]) ? dp[i+1][j-1] : false);
                }
                if(dp[i][j] && j-i+1 > en-st+1){
                    st = i;
                    en = j;
                }
                i++;
                j++;
            }
        }
        return s.substr(st,en-st+1);
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        string ans = "";
        int st = -1;
        int en = -1;
        for(int gap = 1 ; gap <= n ; gap++){
            int i = 0;
            int j = i+gap-1;
            while(j < n){
                if(gap == 1){
                    dp[i][j] = true;
                    st = i;
                    en = j;
                }else if(gap == 2){
                    dp[i][j] = (s[i] == s[j] && (st = i,en = j));
                }else{                    
                    dp[i][j] = (dp[i+1][j-1] && s[i] == s[j] && (st = i,en = j));
                }
                i++;
                j++;
            }
        }
        return s.substr(st,en-st+1);
    }
};
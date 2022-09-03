class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(n == 0 || m == 0){
                if(n){
                    return dp[n][m] = n;
                }else if(m){
                    return dp[n][m] = m;
                }else{
                    return dp[n][m] = 0;
                }
            }

            if(dp[n][m] != -1) return dp[n][m];
            
            int ans = 0;
            if(word1[n-1] != word2[m-1]){
                //end characters are not same
                
                //remove
                int choice1 = go(n-1,m);
                //insert
                int choice2 = go(n,m-1);
                //replace 
                int choice3 = go(n-1,m-1);
                ans = min(choice1,min(choice2,choice3))+1;
            }else{
                //end characters are same
                ans += go(n-1,m-1);
            }
            return dp[n][m] = ans;
        };
        return go(n,m);
    }
};
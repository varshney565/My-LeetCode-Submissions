class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int N,int M){
            for(int n = 0 ; n <= N ; n++){
                for(int m = 0 ; m <= M ; m++){
                    if(n == 0 || m == 0){
                        if(n){
                            dp[n][m] = n;
                        }else if(m){
                            dp[n][m] = m;
                        }else{
                            dp[n][m] = 0;
                        }
                        continue;
                    }

                    int ans = 0;
                    if(word1[n-1] != word2[m-1]){
                        //end characters are not same

                        //remove
                        int choice1 = dp[n-1][m];
                        //insert
                        int choice2 = dp[n][m-1];
                        //replace 
                        int choice3 = dp[n-1][m-1];
                        ans = min(choice1,min(choice2,choice3))+1;
                    }else{
                        //end characters are same
                        ans += dp[n-1][m-1];
                    }
                    dp[n][m] = ans;
                }
            }
            return dp[N][M];
        };
        return go(n,m);
    }
};
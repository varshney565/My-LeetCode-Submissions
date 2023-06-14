class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int gap = 1 ; gap <= n ; gap++){
            for(int i = 0,j = gap-1 ; j < n ; i++,j++){
                int lf = (i-1 >= 0 ? nums[i-1] : 1),rf = (j+1 < n ? nums[j+1] : 1);
                for(int k = i ; k <= j ; k++){
                    dp[i][j] = max(dp[i][j],(i <= k-1 ? dp[i][k-1] : 0)+(k+1 <= j ? dp[k+1][j] : 0)+lf*nums[k]*rf);
                }
            }
        }
        return dp[0][n-1];
    }
};
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //LCS Question ...
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(n == 0 || m == 0)
                return dp[n][m] = 0;
            if(dp[n][m] != -1)
                return dp[n][m];
            if(nums1[n-1] == nums2[m-1]){
                return dp[n][m] = 1+go(n-1,m-1);
            }else{
                return dp[n][m] = max(go(n-1,m),go(n,m-1));
            }
        };
        return go(n,m);
    }
};
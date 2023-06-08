class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        if(sum % 2) return false;
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));
        function<int(int,int)> go = [&](int n,int sum){
            if(sum == 0) return dp[n][sum] = 1;
            if(n == 0) return dp[n][sum] = 0;
            if(dp[n][sum] != -1) return dp[n][sum];
            //not pick
            if(go(n-1,sum)) return dp[n][sum] = 1;
            //pick
            if(sum - nums[n-1] >= 0)
                return dp[n][sum] = go(n-1,sum-nums[n-1]);
            return dp[n][sum] = 0;
        };
        return go(n,sum/2);
    }
};
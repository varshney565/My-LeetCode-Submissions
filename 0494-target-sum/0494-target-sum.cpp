class Solution {
public:
    vector<vector<int>> dp;
    int origin;
    int go(int n,int target,vector<int>&nums){
        if(n == 0){
            return dp[n][target] = (target == origin) ? 1 : 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
        int count = 0;
        //+
        count = go(n-1,target+nums[n-1],nums);
        //-
        count = count + go(n-1,target-nums[n-1],nums);
        return dp[n][target] = count;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        if(target > sum || target < -sum) return 0;
        dp.resize(n+1,vector<int>(2*sum+1,-1));
        origin = sum-target;
        return go(n,target+origin,nums);
    }
};
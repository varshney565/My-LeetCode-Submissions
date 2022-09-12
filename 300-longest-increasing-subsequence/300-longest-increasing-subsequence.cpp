class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
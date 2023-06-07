class Solution {
public:
    
    int go(int n,int target,vector<int>&nums){
        if(n == 0){
            return (target == 0) ? 1 : 0;
        }
        int count = 0;
        //+
        count = go(n-1,target+nums[n-1],nums);
        //-
        count = count + go(n-1,target-nums[n-1],nums);
        return count;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        if(target > sum || target < -sum) return 0;
        return go(n,target,nums);
    }
};
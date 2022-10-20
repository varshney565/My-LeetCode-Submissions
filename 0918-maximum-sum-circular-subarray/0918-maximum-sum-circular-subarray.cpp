class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(),sum = 0,MaxSum = (int)-1e9,MinSum = (int)1e9,cMaxSum = 0,cMinSum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            cMaxSum = max(cMaxSum+nums[i],nums[i]);
            cMinSum = min(cMinSum+nums[i],nums[i]);
            MaxSum = max(MaxSum,cMaxSum);
            MinSum = min(MinSum,cMinSum);
        }
        if(sum == MinSum) return MaxSum;
        return max(MaxSum,sum-MinSum);
    }
};
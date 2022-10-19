class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0)
                nums[i] = -1;
        }
        //now the task is to find the maximum length subarray with sum equals to 0
        map<int,int> cnt;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(sum == 0)
                ans = i+1;
            if(cnt.count(sum) > 0){
                ans = max(ans,i-cnt[sum]);
            }else{
                cnt[sum] = i;
            }
        }
        return ans;
    }
};
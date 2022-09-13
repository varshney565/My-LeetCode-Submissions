class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);
        vector<int> cnt(n,1);
        int ans = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(nums[j] < nums[i]){
                    if(LIS[i] < LIS[j]+1){
                        LIS[i] = LIS[j]+1;
                        cnt[i] = cnt[j];
                    }else if(LIS[i] == LIS[j]+1){
                        cnt[i] += cnt[j];
                    }
                }
            }
            ans = max(ans,LIS[i]);
        }
        for(int i = 0 ; i < n ; i++){
            if(LIS[i] == ans) count += cnt[i];
        }
        return count;
    }
};
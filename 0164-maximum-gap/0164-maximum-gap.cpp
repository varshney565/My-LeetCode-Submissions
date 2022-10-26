class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        int min_ = *min_element(nums.begin(),nums.end());
        int max_ = *max_element(nums.begin(),nums.end());
        int gap = (max_-min_-1+n-1)/(n-1);
        vector<int> Min(n-1,INT_MAX),Max(n-1,INT_MIN);
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == min_ || nums[i] == max_)
                continue;
            int bucketIndex = (nums[i]-min_)/gap;
            Min[bucketIndex] = min(Min[bucketIndex],nums[i]);
            Max[bucketIndex] = max(Max[bucketIndex],nums[i]);
        }
        int ans = gap;
        int prev = min_;
        
        for(int i = 0 ; i < n - 1 ; i++){
            if(Min[i] == INT_MAX) continue;
            ans = max(ans,Min[i]-prev);
            prev = Max[i];
        }
        ans = max(ans,max_-prev);
        return ans;
    }
};
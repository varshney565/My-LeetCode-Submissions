class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_ = INT_MIN;
        int min_ = INT_MAX;
        int ei = -1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < max_)
                ei = i;
            max_ = max(max_,nums[i]);
        }
        
        int si = n;
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i] > min_){
                si = i;
            }
            min_ = min(min_,nums[i]);
        }
        return max(0,ei-si+1);
    }
};
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        int max_ = 0;
        for(int i = 0 ; i < n ; i++){
            max_ = max(max_,nums[i]);
            ans[i] = nums[i]+max_;
            if(i) ans[i] += ans[i-1];
        }
        return ans;
    }
};
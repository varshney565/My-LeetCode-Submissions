class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sum = 0,pre = 0,suf = 0,n = nums.size();
        for(auto x : nums) sum += x;
        suf = sum;
        sort(nums.begin(),nums.end());
        long long ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            suf -= nums[i];
            ans = min(ans,(long long)i*nums[i] - pre + suf-nums[i]*(n-i-1));
            pre += nums[i];
        }
        return ans;
    }
};
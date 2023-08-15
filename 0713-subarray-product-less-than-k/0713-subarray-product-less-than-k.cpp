class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0;
        int en = 0;
        int ans = 0;
        int pro = 1;
        if(k == 0) return 0;
        while(en < n){
            pro *= nums[en];
            while(st <= en && pro >= k){
                pro /= nums[st];
                st++;
            }
            ans += (en-st+1);
            en++;
        }
        return ans;
    }
};
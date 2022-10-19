class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        //sum (k) = sum (atmost k) - sum (atmost k-1);
        auto atmost = [&](int k){
            int st = 0;
            int en = 0;
            int ans = 0;
            int sum = 0;
            while(en < n){
                sum += nums[en];
                while(st <= en && sum > k){
                    sum -= nums[st];
                    st++;
                }
                ans += (en-st+1);
                en++;
            }
            return ans;
        };
        return atmost(k)-atmost(k-1);
    }
};
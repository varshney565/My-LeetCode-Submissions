class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        long long prev_2 = 0,prev_1 = 0;
        int ans = 0;
        const int mod = 1e9+7;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++){
            long long min_ = ((2*prev_2+prev_1)%mod+nums[i])%mod;
            long long val = ((long long)nums[i]*nums[i])%mod;
            int cal = (min_*val)%mod;
            ans = (ans + cal)%mod;
            prev_2 = (prev_2*2)%mod;
            prev_2 = (prev_2+prev_1)%mod;
            prev_1 = nums[i];
        }
        return ans;
    }
};
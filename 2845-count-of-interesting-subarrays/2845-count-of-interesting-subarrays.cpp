class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int cnt = 0;
        map<int,int> f;
        long long ans = 0;
        f[0]++;
        for(int i = 0 ; i < n ; i++) {
            if( nums[i] % modulo == k ) {
                cnt++;
            }
            int r = cnt % modulo;
            int f_r = ( r - k + modulo ) % modulo;
            ans = ans + f[f_r];
            f[r]++;
        }
        return ans;
    }
};
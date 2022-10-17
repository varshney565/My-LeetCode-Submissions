class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int st = 0;
        int en = 0;
        long long sum = 0;
        long long ans = 0;
        while(en < n){
            sum += nums[en];
            while((long long)(sum*(en-st+1)) >= k){
                sum -= nums[st];
                st++;
            }
            ans += (en-st+1);
            en++;
        }
        return ans;
    }
}; 
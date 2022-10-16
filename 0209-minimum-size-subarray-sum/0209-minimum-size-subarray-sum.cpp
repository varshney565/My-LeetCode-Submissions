class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int e = 0;
        int s = 0;
        int sum = 0;
        int ans = n+1;
        while(e < n){
            sum += nums[e];
            while(sum >= target){
                ans = min(ans,e-s+1);
                sum -= nums[s];
                s++;
            }
            e++;
        }
        return (ans == n+1)?0:ans;
    }
};
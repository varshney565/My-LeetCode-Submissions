class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        //map to store the prefix sum frequency.
        map<int,int> cnt;
        int en = 0;
        int sum = 0;
        int ans = 0;
        while(en < n){
            sum += nums[en];
            if(sum == goal)
                ans++;
            //first check then update.
            if(cnt.find(sum-goal) != cnt.end()){
                ans += cnt[sum-goal];
            }
            cnt[sum]++;
            en++;
        }
        return ans;
    }
};
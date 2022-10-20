class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> cnt;
        int ans = 0;
        int sum = 0;
        cnt[0]++;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(cnt.find(sum-k) != cnt.end()){
                ans += cnt[sum-k];
            }
            cnt[sum]++;
        }
        return ans;
    }
};
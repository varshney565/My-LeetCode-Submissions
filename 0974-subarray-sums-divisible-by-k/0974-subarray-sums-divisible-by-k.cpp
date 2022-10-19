class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> cnt;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int rem = (sum%k+k)%k;
            if(rem == 0)
                ans++;
            if(cnt.find(rem) != cnt.end())
                ans += cnt[rem];
            cnt[rem]++;
        }
        return ans;
    }
};
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        auto atmostK = [&](int k){
            map<int,int> cnt;
            int en = 0;
            int st = 0;
            int ans = 0;
            while(en < n){
                cnt[nums[en]]++;
                while(cnt.size() > k){
                    cnt[nums[st]]--;
                    if(cnt[nums[st]] == 0)
                        cnt.erase(nums[st]);
                    st++;
                }
                ans += (en-st+1);
                en++;
            }
            return ans;
        };
        return atmostK(k)-atmostK(k-1);
    }
};
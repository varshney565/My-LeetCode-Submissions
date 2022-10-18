class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        map<int,int> cnt;
        for(int i = 0 ; i < n ; i++){
            cnt[nums[i]]++;
        }
        for(int i = 0 ; i < n ; i++){
            if(cnt.find(nums[i]) == cnt.end()) continue;
            cnt[nums[i]]--;
            if(cnt[nums[i]] == 0)
                cnt.erase(nums[i]);
            if(cnt.find(nums[i]-k) != cnt.end()){
                ans += 1;
            }
            if(k && cnt.find(nums[i]+k) != cnt.end()){
                ans += 1;
            }
            cnt.erase(nums[i]);
        }
        return ans;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        map<int,int> cnt;
        cnt[0] = -1;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int r = sum%k;
            if(cnt.find(r) != cnt.end()){
                int idx = cnt[r];
                if(i-idx >= 2)
                    return true;
            }else{
                cnt[r] = i;
            }
        }
        return false;
    }
};
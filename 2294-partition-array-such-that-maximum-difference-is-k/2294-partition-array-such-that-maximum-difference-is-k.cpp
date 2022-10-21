class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i = n-1;
        while(i >= 0){
            //[1,2,3,5,6]
            int num = nums[i];
            int idx = lower_bound(nums.begin(),nums.end(),num-k)-nums.begin();
            i = idx-1;
            ans++;
        }
        return ans;
    }
};
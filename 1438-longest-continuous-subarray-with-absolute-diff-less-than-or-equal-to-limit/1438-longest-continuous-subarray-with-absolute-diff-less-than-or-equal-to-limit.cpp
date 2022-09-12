class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> MaxMin;
        int n = nums.size();
        int i = 0,j = 0;
        int ans = 0;
        while(j < n){
            MaxMin[nums[j]]++;
            int max_ = (*MaxMin.rbegin()).first;
            int min_ = (*MaxMin.begin()).first;
            while(max_-min_ > limit){
                MaxMin[nums[i]]--;
                if(MaxMin[nums[i]] == 0){
                    MaxMin.erase(nums[i]);
                }
                i++;
                min_ = (*MaxMin.begin()).first;
                max_ = (*MaxMin.rbegin()).first;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> Min,Max;
        int i = 0,j = 0;
        int ans = 0;
        while(j < n){
            while(!Min.empty() && nums[Min.back()] > nums[j]) Min.pop_back();
            while(!Max.empty() && nums[Max.back()] < nums[j]) Max.pop_back();
            Max.push_back(j);
            Min.push_back(j);
            while(nums[Max.front()]-nums[Min.front()] > limit){
                if(Max.front() == i) Max.pop_front();
                if(Min.front() == i) Min.pop_front();
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int en = n-1;
        while(st < en){
            if(nums[st]+nums[en] > target)
                en--;
            else if(nums[st]+nums[en] < target)
                st++;
            else
                return {st+1,en+1};
        }
        return {};
    }
};
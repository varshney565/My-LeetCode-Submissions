class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> F;
        for(int i = 0 ; i < n ; i++){
            if(F.find(target-nums[i]) != F.end()){
                return {F[target-nums[i]],i};
            }
            F[nums[i]] = i;
        }
        return {-1};
    }
};
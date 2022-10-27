class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i = n-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1])
                break;
        }
        if(i == -1){
            reverse(nums.begin(),nums.end());
        }else{
            reverse(nums.begin()+i+1,nums.end());
            auto it = upper_bound(nums.begin()+1+i,nums.end(),nums[i]);
            int idx = it-(nums.begin());
            swap(nums[idx],nums[i]);
        }
    }
};
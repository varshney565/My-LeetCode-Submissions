class Solution {
public:
    vector<vector<int>> k_sum(vector<int>&nums,long long target,int si,int ei,int k){
        if(k == 2){
            int i = si,j = ei;
            vector<vector<int>> ans;
            while(i < j){
                if(nums[i]+nums[j] == target){
                    ans.push_back({nums[i],nums[j]});
                    i++;
                    j--;
                    while(i < j && nums[i] == nums[i-1]) i++;
                    while(i < j && nums[j] == nums[j+1]) j--;
                }else if(nums[i]+nums[j] > target) j--;
                else i++;
            }
            return ans;
        }
        
        vector<vector<int>> ans;
        for(int i = ei ; i >= si ; ){
            vector<vector<int>> SmallAns = k_sum(nums,target-nums[i],si,i-1,k-1);
            for(auto &x : SmallAns){
                x.push_back(nums[i]);
                ans.push_back(x);
            }
            i--;
            while(i >= si && nums[i] == nums[i+1]) i--;
        }
        return ans;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans = k_sum(nums,(long long)target,0,nums.size()-1,4);
        return ans;
    }
};
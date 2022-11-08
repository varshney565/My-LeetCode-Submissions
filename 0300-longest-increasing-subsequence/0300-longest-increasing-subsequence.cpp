class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int s = 0;
            int e = LIS.size()-1;
            while(s <= e){
                int mid = (s+e)/2;
                if(LIS[mid] < nums[i]){
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }
            //s is the upper_bound
            if(s == LIS.size())
                LIS.push_back(nums[i]);
            else LIS[s] = nums[i];
        }
        return LIS.size();
    }
};
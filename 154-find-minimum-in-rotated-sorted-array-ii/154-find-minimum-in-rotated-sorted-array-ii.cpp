class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int ans = INT_MAX;
        while(s <= e){
            int mid = (s+e)/2;
            if(nums[mid] > nums[e]){
                s = mid+1;
            }else if(nums[mid] < nums[e]){
                ans = min(ans,nums[mid]);
                e = mid-1;
            }else{
                e--;
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            int st = 0;
            int en = i-1;
            while(st < en){
                if(nums[st]+nums[en] <= nums[i]){
                    st++;
                }else{
                    ans += (en-st);
                    en--;
                }
            }
        }
        return ans;
    }
};
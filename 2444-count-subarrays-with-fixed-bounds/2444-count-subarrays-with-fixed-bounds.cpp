class Solution {
public:
    long long go(vector<int>&nums,int si,int ei,int minK,int maxK){
        if(si > ei) return 0;
        long long maxPos = si-1;
        long long minPos = si-1;
        int n = ei-si+1;
        long long ans = 0;
        for(int i = si ; i <= ei ; i++){
            if(nums[i] == maxK) maxPos = i;
            if(nums[i] == minK) minPos = i;
            ans += min(maxPos,minPos)-si+1ll;
        }
        return ans;
    }
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int si = 0;
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(minK > nums[i] || maxK < nums[i]){
                ans += go(nums,si,i-1,minK,maxK);
                si = i+1;
            }
        }
        ans += go(nums,si,n-1,minK,maxK);
        return ans;
    }
};
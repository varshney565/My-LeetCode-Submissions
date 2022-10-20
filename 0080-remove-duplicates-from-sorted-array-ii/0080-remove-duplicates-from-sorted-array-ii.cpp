class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int en = 1;
        int cnt = 1;
        int k = 2;
        for(; en < n ; en++){
            //element at starting index now has frequency k
            if(nums[en] == nums[st] && cnt == k)
                continue;
            //element at starting index is not equal to en means new elements comes
            if(nums[en] != nums[st])
                cnt = 0;
            nums[++st] = nums[en];
            cnt++;
        }
        return st+1;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int en = 1;
        int cnt = 1;
        for(; en < n ; en++){
            //element at starting index now has frequency 2. 
            if(nums[en] == nums[st] && cnt == 2)
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
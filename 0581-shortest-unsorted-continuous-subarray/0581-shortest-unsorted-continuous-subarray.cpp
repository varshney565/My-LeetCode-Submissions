class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = n;
        deque<int> d;
        for(int i = 0 ; i < n ; i++){
            int idx = n;
            while(d.size() > 0 && nums[d.back()] > nums[i]){
                idx = d.back();
                d.pop_back();
            }
            d.push_back(i);
            s = min(s,idx);
        }
        int e = 0;
        d.clear();
        for(int i = n-1 ; i >= 0 ; i--){
            int idx = -1;
            while(d.size() > 0 && nums[d.back()] < nums[i]){
                idx = d.back();
                d.pop_back();
            }
            d.push_back(i);
            e = max(e,idx);
        }
        return max(0,e-s+1);
    }
};
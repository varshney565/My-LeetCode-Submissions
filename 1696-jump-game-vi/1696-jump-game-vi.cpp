class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> d;
        int i = 1;
        d.push_back({0,nums[0]});
        while(i < n){
            int max_ = d.front().second;
            if(d.front().first<=i-k)
                d.pop_front();
            //insert the ith value.
            while(!d.empty() && d.back().second <= nums[i]+max_){
                d.pop_back();
            }
            d.push_back({i,nums[i]+max_});
            i++;
        }
        return d.back().second;
    }
};
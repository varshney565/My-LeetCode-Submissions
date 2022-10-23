class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> d;
        int i = 0;
        while(i < n){
            //erase all the elements that needed to be deleted.
            while(!d.empty() && d.front().first < i-k)
                d.pop_front();
            //do the processing.
            int max_ = (d.empty()?0:d.front().second)+nums[i];
            //insert all the needed elements.
            while(!d.empty() && d.back().second < max_)
                d.pop_back();
            d.push_back({i,max_});
            i++;
        }
        return d.back().second;
    }
};
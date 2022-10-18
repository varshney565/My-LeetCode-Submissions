class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;
        int n = nums.size();
        //processing first k elements.
        for(int i = 0 ; i < k ; i++){
            if(d.size() == 0){
                d.push_back(i);
            }else{
                while(d.size() > 0 && nums[d.back()] < nums[i]){
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
        ans.push_back(nums[d.front()]);
        //processing the remaining elements
        for(int i = k ; i < n ; i++){
            //remove the elements which are not part of the current window.
            while(d.size() > 0 && d.front() <= i-k){
                d.pop_front();
            }
            
            if(d.size() == 0){
                d.push_back(i);
            }else{
                while(d.size() > 0 && nums[d.back()] < nums[i]){
                    d.pop_back();
                }
                d.push_back(i);
            }
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};
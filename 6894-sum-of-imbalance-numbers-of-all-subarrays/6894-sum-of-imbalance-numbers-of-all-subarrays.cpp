class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int st = 0 ; st < n ; st++){
            vector<int> arr(n+1,0);
            arr[nums[st]] = 1;
            int cnt = 0,min_ = nums[st],max_ = nums[st];
            for(int en = st + 1 ; en < n ; en++){
                if(arr[nums[en]]){
                    ans += cnt;
                    continue;
                }
                arr[nums[en]] = 1;
                if(nums[en] > min_ && nums[en] < max_){
                    if(arr[nums[en]-1] || arr[nums[en]+1])
                        cnt--;
                }
                min_ = min(min_,nums[en]);
                max_ = max(max_,nums[en]);
                if(min_ == nums[en]){
                    if(min_ < n-1 && arr[min_+1] == 0) cnt++;
                }else if(max_ == nums[en]){
                    if(max_ > 1 && arr[max_-1] == 0) cnt++;
                }else{
                    if(nums[en] < n-1 && arr[nums[en]+1] == 0) cnt++;
                    else if(nums[en] > 1 && arr[nums[en]-1] == 0) cnt++;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};
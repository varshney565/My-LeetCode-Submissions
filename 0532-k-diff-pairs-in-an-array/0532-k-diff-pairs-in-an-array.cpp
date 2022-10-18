class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> cnt;
        //take each and every element in the set in prior.
        for(int i = 0 ; i < n ; i++){
            cnt[nums[i]]++;
        }
        
        for(int i = 0 ; i < n ; i++){
            //if nums[i] is not in the set mean it is already processed.
            if(cnt.find(nums[i]) == cnt.end()) continue;
            //decreasing the frequency just to avoid the case when k = 0,
            //because in that case nums[i]-k will lead to the same element
            //so there must be one more element of the same type at different index,
            //for holding the condition to be true.
            cnt[nums[i]]--;
            if(cnt[nums[i]] == 0)
                cnt.erase(nums[i]);
            //checking whether nums[i]-k is present in the set or not.
            if(cnt.find(nums[i]-k) != cnt.end()){
                ans += 1;
            }
            //checking whether nums[i]+k is present in the set or not.
            //in case k is zero the both nums[i]-k and nums[i]+k will lead to the same element so 
            //making sure that k is positive for nums[i]+k.
            if(k && cnt.find(nums[i]+k) != cnt.end()){
                ans += 1;
            }
            //deleting the nums[i] from the set,because it is processed now.
            cnt.erase(nums[i]);
        }
        return ans;
    }
};
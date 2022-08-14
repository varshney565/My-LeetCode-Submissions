class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++){
            while(i < n && i > 0 && nums[i] == nums[i-1]){
                ++i;
            }
            int s = i+1;
            int e = n-1;
            while(s < e){
                if(nums[i] + nums[s] + nums[e] > 0){
                    e--;
                }else if(nums[i] + nums[s] + nums[e] < 0){
                    s++;
                }else{
                    ans.push_back({nums[i],nums[s],nums[e]});
                    int u = nums[s];
                    int v = nums[e];
                    while(e > i && nums[e] == v){
                        e--;
                    }
                    while(s <= e && nums[s] == u){
                        s++;
                    }
                }
            }
        }
        return ans;
    }
};
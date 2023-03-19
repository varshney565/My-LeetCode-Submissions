
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;
        int n = nums.size();
        int cnt = 0;
        while(i < n && j < n){
            if(nums[i] < nums[j]){
                i++;
                j++;
                cnt++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};
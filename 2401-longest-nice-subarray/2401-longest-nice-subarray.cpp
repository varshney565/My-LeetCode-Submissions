class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int bitOr = nums[0];
        int j = 0;
        for(int i = 1 ; i < n ; i++){
            if((bitOr & nums[i]) == 0){
                ans = max(i-j+1,ans);
            }else{
                int conflict = (nums[i]&bitOr);
                while(conflict){
                    conflict ^= (conflict&nums[j]);
                    bitOr = (bitOr^nums[j]);
                    j++;
                }
            }
            bitOr |= nums[i];
        }
        return ans;
    }
};
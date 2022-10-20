class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = -1;
        int i = 0;
        int blue = n;
        while(i < blue){
            if(nums[i] == 1)
                i++;
            else if(nums[i] == 0){
                swap(nums[i],nums[++red]);
                i++;
            }else if(nums[i] == 2){
                swap(nums[i],nums[--blue]);
            }
        }
    }
};